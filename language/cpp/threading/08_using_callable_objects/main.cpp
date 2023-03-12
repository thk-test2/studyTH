#include <iostream>
#include <thread>
#include <future>

using namespace std;

class A {
public:
	void f(int x, int c) { }
	long g(double x) { return 0; }
	int operator()(int N) { return 0; }
};

void foo(int x) {}

int main() {
	A a;

	// 2 ways of creating child thread
	thread t1(a, 6);      // copy_of_a() in a different thread
	thread t2(ref(a), 6); // a() in a different thread
	thread t3(A(), 6);    // temporary A;
	// thread t3_2(move(a), 6);    // a is no longer usable in main thread


	thread t4([](int x) { return x * x; }, 6);
	thread t5(foo, 7);

	thread t6(&A::f, a, 8, 'w'); // copy_of_a.f(8, 'w') in a different thread
	thread t7(&A::f, &a, 8, 'w'); // a.f(8, 'w') in a different thread

	//async(launch::async, a, 6);

	//bind(a, 6);
	//once_flag flag1;
	//call_once(flag1, a, 6);
	return 0;
}