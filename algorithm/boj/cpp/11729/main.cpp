#include <iostream>
#include <vector>

using namespace std;

void hanoi(int n, int start, int to, int via, vector<pair<int, int>>& v) {
    if (n == 0)
        return;

    hanoi(n-1, start, via, to, v);
//    cout << "move " << n << " from " << start << ", to " << to << endl;
    v.push_back(make_pair(start, to));
    hanoi(n-1, via, to, start, v);
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    hanoi(N, 1, 3, 2, v);
    printf("%d\n", v.size());
    for (const auto& itr: v) {
        printf("%d ", itr.first);
        printf("%d\n", itr.second);
//        cout << itr.first << " " << itr.second << endl;
    }

    return 0;
}
