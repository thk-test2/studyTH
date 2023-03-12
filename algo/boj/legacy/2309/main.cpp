#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solution(vector<int>& A) {
    vector<int> mask = {0,0,1,1,1,1,1,1,1};
    vector<int> partial;

    do {
        for(int i=0; i<mask.size(); i++){
            if (mask[i] == 1){
                partial.push_back(A[i]);
            }
        }
        if (int sum = accumulate(begin(partial), end(partial), 0) ; sum == 100) {
            break;
        }
        partial.clear();

    } while(next_permutation(mask.begin(), mask.end()));

    sort(begin(partial), end(partial));
    for (const auto& n : partial)
        cout << n << endl;
}

int main()
{
    int height;
    vector<int> numbers;

    for(int i = 0; i < 9; i++) {
        cin >> height;
        numbers.push_back(height);
    }
    solution(numbers);
    return 0;
}
