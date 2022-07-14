#include <iostream>
#include <thread>

using namespace std;

void func() {
    cout << "Hello World!" << endl;
}

class Fctor {
public:
    void operator()(string && msg) {
        cout << "t1 says: " << msg << "\n";
        msg = "Changed !!";
        //for (int i = 0; i > -100; --i) {
        //    cout << "from t1: " << i << "\n";
        //}
    }
};

int main()
{
    //thread t1(func); // t1 starts running
    // using RAII
    // Wrapper w(t1);
    string s = "TEST TEST";
    thread t1((Fctor()), move(s));
    //t1.join();

    thread t2 = move(t1);
    t2.join();
    
    cout << "from main: " << s << "\n";

    cout << thread::hardware_concurrency(); // Available threads

    //try {
    //    cout << "from main: " << s << "\n";
    //    //for (int i = 0; i < 100; ++i) {
    //    //    cout << "from main: " << i << "\n";
    //    //}
    //}
    //catch (...) {
    //    t1.join();
    //    throw;
    //}

    //t1.join();
    return 0;
}
