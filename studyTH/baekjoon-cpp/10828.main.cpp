#include <iostream>

class Stack {
    int top_height = -1;
    int pstack[10000];

public:
    inline void push(int n) {
        if (top_height == 9999)
            return;
        pstack[++top_height] = n;
    }
    inline int pop() { return top_height == -1 ? -1 : pstack[top_height--]; }
    inline int size() { return top_height+1; }
    inline bool empty() { return top_height == -1 ? 1 : 0; }
    inline int top() { return top_height == -1 ? -1 : pstack[top_height]; }
};

int main() {
    // constexpr int MAX = 10000;
    Stack _stack;
    int operation_count = 0;
    std::cin >> operation_count;

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