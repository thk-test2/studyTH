#include <iostream>
#include <vector>

using namespace std;
class MinStack {
    int min_val = INT_MAX;
    vector<pair<int, int>> st;
public:
    MinStack() {

    }

    void push(int val) {
        if (st.empty())
            min_val = INT_MAX;
        min_val = min(min_val, val);

        st.push_back({ val, min_val });
    }

    void pop() {
        st.pop_back();
        if (!st.empty())
            min_val = st.back().second;
    }

    int top() {
        return st.back().first;
    }

    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {
	
	return 0;
}