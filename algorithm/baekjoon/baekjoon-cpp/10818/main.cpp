#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int>& A) {
    cout << *min_element(A.begin(), A.end()) << " "
         << *max_element(A.begin(), A.end());
}

int main()
{
    int N, t;
    cin >> N;
    vector<int> numbers;

    for(int i = 0; i < N; i++) {
        cin >> t;
        numbers.push_back(t);
    }
    solution(numbers);
    return 0;
}
