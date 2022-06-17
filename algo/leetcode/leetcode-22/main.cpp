#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string temp;
        checknode(temp, 0, 0, 0, n);
        return answer;
    }

    void checknode(string temp, int leftSelected, int rightSelected,
        int level, int n) {
        if (level == 2 * n) {
            answer.push_back(temp);
            return;
        }

        if (leftSelected < n) {
            temp += '(';
            checknode(temp, leftSelected + 1, rightSelected, level + 1, n);
            temp.pop_back();
        }

        if (leftSelected > rightSelected) {
            temp += ')';
            checknode(temp, leftSelected, rightSelected + 1, level + 1, n);
            temp.pop_back();
        }
    }
    vector<string> answer;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}