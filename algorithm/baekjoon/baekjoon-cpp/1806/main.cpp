#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;

    vector<int> v;
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }

    vector<int>::iterator p1 = v.begin();
    vector<int>::iterator p2 = v.begin();
    int sum = *p2;
    int cnt = 1;
    int minimum = 100001;
    while (p1 <= p2 && p2 != v.end()) {
        if (sum >= S && cnt != 0) {
            minimum = min(minimum, cnt);
            sum -= *p1;
            p1++;
            cnt--;
        } else if (sum < S) {
            p2++;
            cnt++;
            sum += *p2;
        }
    }
    if (minimum != 100001)
        cout << minimum;
    else
        cout << 0;

    return 0;
}
