#include <iostream>
#include <vector>

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
        std::cout << "+" << std::endl;
    }
    T pop() { 
        int ret = empty() ? -1 : pstack_[top_--];
        std::cout << "-" << std::endl;
        return ret;
    }
    bool empty() { return top_ == -1 ? true : false; }
    int size() { return top_+1; }
    T top() { return empty() ? -1 : pstack_[top_]; }
};

int main() {
    int operation_count = 0;
    std::cin >> operation_count;
    MyStack<int> _stack(operation_count);

    std::vector<int> myvec;

    for (int i = operation_count ; i > 0 ; i--)
        myvec.push_back(i);

    int number;
    std::string error_text;

    for (int i = 1 ; i <= operation_count ; i++) {
        std::cin >> number;

        while ( _stack.top() != number ) {
            if (_stack.top() < number ) {
                _stack.push(myvec.back());
                myvec.pop_back();
                continue;
            }
            else {
                error_text = "NO";
                break;
            }
        }
        if ( !error_text.empty() ) {
            std::cout << error_text << std::endl;
            break;
        }
        _stack.pop();
    }
}
