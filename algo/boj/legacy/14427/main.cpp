#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using mydata = pair<int, int>;

int N, M;
int tree[100000*4 + 1];
int arr[100001];

int minIndex(int a, int b) {
    if (arr[a] == arr[b])
        return a < b ? a : b ;
    else
        return arr[a] < arr[b] ? a : b;
}

int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = start;

    int mid = (start + end) / 2;
    int left = init(node*2, start, mid);
    int right = init(node*2+1, mid+1, end);

    return tree[node] = minIndex(left, right);
}

int update(int node, int start, int end, int index) {
    if (index < start || index > end || start == end)
        return tree[node];
    int mid = (start + end) / 2;
    int left = update(node*2, start, mid, index);
    int right = update(node*2+1, mid+1, end, index);
    return tree[node] = minIndex(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> n;
        arr[i] = n;
    }
    init(1, 1, N);

    cin >> M;
    int cmd, I, V;
    for (int i = 1; i <= M; i++) {
        cin >> cmd;
        if (cmd == 2) {
            cout << tree[1] << "\n";
        } else {
            cin >> I >> V;
            arr[I] = V;
            update(1, 1, N, I);
        }
    }

    return 0;
}
