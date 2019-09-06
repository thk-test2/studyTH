#include <iostream>
#include <list>

using namespace std;

template <typename T, typename C = list<T>> class Queue
{
    C lt;
public:
    inline void Push(const T& a) { lt.push_back(a); }
    inline T Pop() { T result = lt.front(); lt.pop_front(); return result; }
};

int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    cout << q.Pop() << endl; // 10
    cout << q.Pop() << endl; // 20
}