#include <iostream>

template <typename T>
class MyStack {

    T* pstack_ = nullptr;
    int top_ = -1;
    int max_ = 0;

public:
    MyStack(int n) {
        max_ = n;
        pstack_ = new T[max_];
    }

    void push(T n) {
        if ( top_ < max_ )
            pstack_[++top_] = n; 
    }
    T pop() { return empty() ? -1 : pstack_[top_--]; }
    bool empty() { return top_ == -1 ? true : false; }
    int size() { return top_+1; }
    T top() { return empty() ? -1 : pstack_[top_]; }
};

int main() {
    int operation_count = 0;
    std::cin >> operation_count;
    MyStack<int> _stack(operation_count);

    std::string operation;

    for (int i = 0 ; i < operation_count ; i++) {
        std::cin >> operation;

        if (operation == "push") {
            int temp;
            std::cin >> temp;
            _stack.push(temp);
        }
        else if( operation == "pop")
            std::cout << _stack.pop() << std::endl;
        else if( operation == "size")
            std::cout << _stack.size() << std::endl;
        else if( operation == "empty")
            std::cout << _stack.empty() << std::endl;
        else if( operation == "top")
            std::cout << _stack.top() << std::endl;
    }
}
