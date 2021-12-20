#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int X;
    cin >> X;

    vector<int> v;
    v.push_back(64);
    while (1) {
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum > X) {
            int small = v.front();
            v.erase(v.begin());
            if ( (sum - small/2) >= X) {
                v.push_back(small/2);
            } else {
                v.push_back(small/2);
                v.push_back(small/2);
            }
        } else if (sum == X) {
            break;
        }
        sort(v.begin(), v.end());
    }
    cout << v.size();

    return 0;
}
