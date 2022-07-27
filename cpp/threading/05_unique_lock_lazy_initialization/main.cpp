#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
    mutex _mu;
    mutex _mu_file;
    once_flag _flag;
    ofstream f;
public:
    LogFile() {
    }
    // Need destructor to close file
    void shared_print2(string id, int val) {
        //{
        //    unique_lock<mutex> locker2(_mu_file);
        //    if (!f.is_open()) { // Lazy Initialization
        //        f.open("log.txt");
        //    }
        //}

        // file will be opened only once by one thread
        call_once(_flag, [&]() {_f.open("log.txt"); });

        unique_lock<mutex> locker(_mu, defer_lock);
        cout << "From " << id << ": " << val << "\n";
    }

    void shared_print(string id, int val) {
        //lock_guard<mutex> locker(_mu);

        unique_lock<mutex> locker(_mu, defer_lock);

        locker.lock();
        cout << "From " << id << ": " << val << "\n";
        locker.unlock();

        //...

        unique_lock<mutex> locker2 = move(locker);
    }
};

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
