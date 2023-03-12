#include <iostream>
#include <future>

using namespace std;

// Too complicated
//mutex mu;
//condition_variable cond;

//int factorial(int N) {
//int factorial(future<int>& f) {
int factorial(shared_future<int> f) {
	int res = 1;

	int N = f.get(); // exception: future_errc::broken_promise
	for (int i = N; i > 1; --i)
		res *= i;
	cout << "Result is: " << res << "\n";
	return res;
}

int main() {
	int x;

	//thread t1(factorial, 4, ref(x));
	//t1.join();

	// channel to get the result from child thread
	//future<int> fu = async(factorial, 4);

	// Will not create a thread. when get() is called, will be executed in same thread.
	//future<int> fu = async(launch::deferred, factorial, 4);

	// the child thread creation depends on the implementation.
	//future<int> fu = async(launch::async | launch::deferred, factorial, 4);

	// Make sure child thread will be created
	//future<int> fu = async(launch::async, factorial, 4);
	//x = fu.get();

	// fu.get(); crash!


	// Send a value to the child, and the value will be send in a future. That is my promise
	promise<int> p;
	future<int> f = p.get_future();
	shared_future<int> sf = f.share(); // can be copied

	future<int> fu = async(launch::async, factorial, sf);
	future<int> fu2 = async(launch::async, factorial, sf);
	future<int> fu3 = async(launch::async, factorial, sf);
	//... 10 threads

	// do something else
	this_thread::sleep_for(chrono::milliseconds(20));

	//p.set_exception(make_exception_ptr(runtime_error("To err is human")));
	p.set_value(4);

	x = fu.get();
	cout << "Get from child: " << x << "\n";

	return 0;
}