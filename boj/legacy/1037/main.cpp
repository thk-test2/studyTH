#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, n;
    vector<int> numbers;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        numbers.push_back(n);
    }

    cout << (*max_element(begin(numbers), end(numbers))) *
            (*min_element(begin(numbers), end(numbers))) << endl;

    return 0;
}
