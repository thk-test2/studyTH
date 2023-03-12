#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>

using namespace std;

int factorial(int N) {
    int res = 1;
    for (int i = N; i > 1; --i)
        res *= i;
    cout << "Result is: " << res << "\n";
    return res;
}

int main() {
    /* Thread */
    thread t1(factorial, 6);

    this_thread::sleep_for(chrono::milliseconds(3));
    chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::microseconds(4);
    this_thread::sleep_until(tp);

    /* Mutex */
    mutex mu;
    lock_guard<mutex> locker(mu);
    unique_lock<mutex> ulocker(mu);

    ulocker.try_lock();
    ulocker.try_lock_for(chrono::nanoseconds(500));
    ulocker.try_lock_until(tp);

    /* Condition Variable */
    condition_variable cond;

    cond.wait_for(ulocker, chrono::microseconds(2));
    cond.wait_until(ulocker, tp);

    /* Future and Promise*/
    promise<int> p;
    future<int> f = p.get_future();

    f.get();
    f.wait();
    f.wait_for(chrono::milliseconds(2));
    f.wait_until(tp);

    /* async() */
    future<int> fu = async(factorial, 6);

    /* Packaged tasks */
    packaged_task<int(int)> t(factorial);
    future<int> fu2 = t.get_future();
    t(6);
	
	return 0;
}