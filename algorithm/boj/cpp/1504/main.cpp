#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, E;
int v1, v2;
vector<pair<int, int>> arr[801];
int dp[801];

struct MyLess {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first
    }
};

void dikstra_modified() {

}

int main()
{
    cin >> N >> E;

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b, c));
    }

    return 0;
}
