#include <iostream>

template <typename T>
class MyQueue {
    T pq[10000];
    int size_= 0;
    int front_ = 0;
    int back_ = 0;

public:
    void push(T n) { 
        if (size_ >= 10000) return;

        if (empty())
            pq[back_] = n;
        else
            pq[++back_ % 10000] = n;
        size_++;
     }
    T pop() {
        if (empty()) return -1;

        T ret;

        if (size_ == 1)
            ret = pq[front_];
        else
            ret = pq[front_++ % 10000];
        size_--;
        return ret;
    }
    inline int size() { return size_; }
    inline bool empty() { return !size_; }
    T front() { 
        if (empty()) return -1;
        return pq[front_]; 
    }
    T back() {
        if (empty()) return -1;
        return pq[back_]; 
    }
};

int main() {
    MyQueue<int> _queue;
    int operation_count = 0;
    std::cin >> operation_count;

    std::string operation;

    for (int i = 0 ; i < operation_count ; i++) {
        std::cin >> operation;

        if (operation == "push") {
            int temp;
            std::cin >> temp;
            _queue.push(temp);
        }
        else if( operation == "pop")
            std::cout << _queue.pop() << std::endl;
        else if( operation == "size")
            std::cout << _queue.size() << std::endl;
        else if( operation == "empty")
            std::cout << _queue.empty() << std::endl;
        else if( operation == "front")
            std::cout << _queue.front() << std::endl;
        else if( operation == "back")
            std::cout << _queue.back() << std::endl;
    }
}