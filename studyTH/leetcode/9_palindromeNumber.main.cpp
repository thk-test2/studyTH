#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);

        bool ret = true;
        for (int i = 0 ; i < str.length()/2; i++) {
            // std::cout << str.at(i) << ", " << str.at(str.length() -1 -i) << std::endl;
            if ( str.at(i) != str.at(str.length()- 1 - i) ) {
                ret = false;
            }
        }
        return ret;
    }
};

int main() {

    Solution sol;
    int N;
    std::cin >> N;
    std::string ret = sol.isPalindrome(N) ? "true" : "false";
    std::cout << ret << std::endl;

    return 0;
}