#include <iostream>
#include <future>
#include <deque>

using namespace std;

int factorial(int N) {
	int res = 1;
	for (int i = N; i > 1; --i)
		res *= i;
	cout << "Result is: " << res << "\n";
	return res;
}

deque<packaged_task<int()>> task_q;
mutex mu;
condition_variable cond;

void thread_1() {
	packaged_task<int()> t;
	{
		unique_lock<mutex> locker(mu);
		cond.wait(locker, []() {return !task_q.empty(); });
		t = move(task_q.front());
		task_q.pop_front();
	}
	t();
}

/* Summary: 3 ways to get a future
1. promise::get_future();
2. packaged_task::get_future();
3. async() returns a future
*/

int main() {
	packaged_task<int(int)> t(factorial);

	// ...

	t(6); // Executed in a different context
	int x = t.get_future().get();

	packaged_task<int()> t2(bind(factorial, 6));
	t2();

	// Why packaged_task is needed? Because of supporting future.
	auto t3 = bind(factorial, 6);
	t3();

	thread t1(thread_1);
	packaged_task<int()> t4(bind(factorial, 6));
	future<int> fu = t4.get_future();
	{
		lock_guard<mutex> locker(mu);
		task_q.push_back(move(t4));
	}
	cond.notify_one();

	cout << fu.get() << "\n";

	t1.join();

	return 0;
}