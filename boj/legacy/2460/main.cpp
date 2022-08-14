#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int>& A) {
    cout << *max_element(A.begin(), A.end());
}

int main()
{
    int minus, plus;
    int current = 0;
    vector<int> numbers;

    for(int i = 0; i < 10; i++) {
        cin >> minus;
        cin >> plus;
        current = current - minus + plus;
        numbers.push_back(current);
    }
    solution(numbers);
    return 0;
}
