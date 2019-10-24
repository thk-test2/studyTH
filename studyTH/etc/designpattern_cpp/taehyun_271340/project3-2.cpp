#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue : public list<T>
{
private:
    typedef list<T> super;
public:
    void Push(T n) { this->push_back(n); }
    T Pop() { T result = this->front(); this->pop_front(); return result; }
};

int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    cout << q.Pop() << endl; // 10
    cout << q.Pop() << endl; // 20
}