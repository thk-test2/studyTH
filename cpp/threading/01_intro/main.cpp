#include <iostream>
#include <thread>

// https://www.youtube.com/watch?v=LL8wkskDlbs&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=1&ab_channel=BoQian

using namespace std;

void func() {
    cout << "Hello World!" << endl;
}

int main()
{
    thread t1(func);
    //    t1.join();
    t1.detach();

    if (t1.joinable())
        t1.join();
    return 0;
}
