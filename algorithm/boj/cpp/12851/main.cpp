#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool inserted[100001] = {false};

void findbro(vector<int>& v, int N, int K) {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    inserted[N] = true;

    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        inserted[temp.first] = true;
//        cout << temp.first << " ," << temp.second << endl;

        if (temp.first == K) {
            v.push_back(temp.second);
            continue;
        }

        if (temp.first > 0 && !inserted[temp.first-1]) {
            q.push(make_pair(temp.first-1, temp.second+1));
        }
        if (temp.first < 100000 && !inserted[temp.first+1]) {
            q.push(make_pair(temp.first+1, temp.second+1));
        }
        if (temp.first <= 50000 && !inserted[2*temp.first]) {
            q.push(make_pair(2*temp.first, temp.second+1));
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> v;
    findbro(v, N, K);

    int minimum = *min_element(v.begin(), v.end());
    int cnt = count(v.begin(), v.end(), minimum);
    cout << minimum << endl << cnt;

    return 0;
}
