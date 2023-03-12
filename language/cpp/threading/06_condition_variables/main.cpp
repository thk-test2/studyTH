#include <iostream>
#include <queue>
#include <mutex>

using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;

void f1() {
	int count = 10;
	while (count > 0) {
		unique_lock<mutex> locker(mu);
		
		q.push_front(count); // shared memory
		locker.unlock();
		cond.notify_one(); // Notify one waiting thread, if there is one.
		cond.notify_all();

		this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void f2() {
	int data = 0;
	while (data != 1) {
		unique_lock<mutex> locker(mu);
		cond.wait(locker, []() { return !q.empty(); } ); // spurious wake

		data = q.back();
		q.pop_back();

		locker.unlock();
		cout << "t2 got a value from t1: " << data << endl;
	}
}

//void f2() {
//	int data = 0;
//	while (data != 1) {
//		unique_lock<mutex> locker(mu);
//		if (!q.empty()) {
//			data = q.back();
//			q.pop_back();
//			locker.unlock();
//			cout << "t2 got a value from t1: " << data << endl;
//		}
//		else {
//			locker.unlock();
//			this_thread::sleep_for(chrono::milliseconds(10));
//		}
//	}
//}

int main() {
	thread t1(f1);
	thread t2(f2);

	t1.join();
	t2.join();
	
	return 0;
}