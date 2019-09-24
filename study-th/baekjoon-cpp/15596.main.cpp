#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
    long long result = 0;

    for(auto iter : a) {
        result += iter;
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    long long result = sum(a);
    std::cout << result << std::endl;

    return 0;
}