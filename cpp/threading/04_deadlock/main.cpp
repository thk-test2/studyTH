#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
    mutex _mu;
    mutex _mu2;
    ofstream f;
public:
    LogFile() {
        f.open("log.txt");
    }
    // Need destructor to close file
    void shared_print(string id, int val) {
        lock(_mu, _mu2);
        lock_guard<mutex> locker(_mu, adopt_lock);
        lock_guard<mutex> locker2(_mu2, adopt_lock);
        cout << "From " << id << ": " << val << "\n";
    }

    void shared_print2(string id, int val) {
        //lock_guard<mutex> locker(_mu); // Use mutex in same order.
        //lock_guard<mutex> locker2(_mu2);

        lock(_mu, _mu2);
        lock_guard<mutex> locker(_mu, adopt_lock);
        lock_guard<mutex> locker2(_mu2, adopt_lock);
        cout << "From " << id << ": " << val << "\n";
    }

    void shared_print3(string id, int val) {
        {
            lock_guard<mutex> locker(_mu);
            //...
        }
        {
            lock_guard<mutex> locker2(_mu2);
        }
        cout << "From " << id << ": " << val << "\n";
    }
};

/* Avoiding deadlock
1. Prefer locking single mutex.
2. Avoid locking a mutex and then calling a user provided function
3. Use std::lock() to lock more than one mutex.
4. Lock the mutex in same order.

Locking Granularity:
- Fine-grained lock: protects small amount of data
- Coarse-grained lock: protects big amount of data
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
        log.shared_print2("From main: ", i);
    }

    t1.join();

    return 0;
}
