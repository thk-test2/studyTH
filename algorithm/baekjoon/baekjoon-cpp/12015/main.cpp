#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int>& sub, int key) {
    int start = 0;
    int end = sub.size() - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (key > sub[mid]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

int main()
{
    int N, n;
    cin >> N;

    int arr[N];
    int dp[N];
    for (int i = 0; i < N; i++) {
        cin >> n;
        arr[i] = n;
        dp[i] = 1;
    }

    vector<int> sub;
    sub.push_back(arr[0]);
    for (int i = 1; i < N; i++) {
        if (arr[i] > sub.back()) {
            sub.push_back(arr[i]);
        }
        else {
            sub[bs(sub, arr[i])] = arr[i];
        }
    }
    cout << sub.size();

    return 0;
}
