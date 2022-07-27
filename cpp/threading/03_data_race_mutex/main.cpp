#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

//mutex mu;
//
//void shared_print(string msg, int id) {
//	//mu.lock();
//	lock_guard<mutex> guard(mu);  // RAII: for case of exception
//
//	cout << msg << id << "\n";
//	//mu.unlock();
//}

class LogFile {
	mutex m_mutex;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}
	// Need destructor to close file
	void shared_print(string id, int val) {
		lock_guard<mutex> locker(m_mutex);
		f << "From " << id << ": " << val << "\n";
	}

	// Never return f to the outside world
	//ofstream& getStream() { return f; }

	// Never pass f as an augument to user provided function
	//void processf(void fun(ofstream&)) {
	//	fun(f);
	//}
};

class stack {
	int* _data;
	mutex _mu;
public:
	void pop(); // pops off the item on top. this should return int&
	int& top(); // returns the item on top
	//...
};

// thread safe?
void f_2(stack& st) {
	int v = st.top();
	st.pop();
	process(v);
}

/* Avoiding Data Race:
1. Use mutex to synchronize data access
2. Never leak a handle of data to outside
3. Design interface appropriately.
*/

void function_1(LogFile& log) {
	for (int i = 0; i > -100; --i) {
		//cout << "From t1: " << i << "\n";
		log.shared_print("From t1: ", i);
	}
}

int main() {
	LogFile log;
	thread t1(function_1, ref(log));

	for (int i = 0; i < 100; ++i) {
		//cout << "From main: " << i << "\n";
		log.shared_print("From main: ", i);
	}

	t1.join();

	return 0;
}