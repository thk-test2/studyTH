#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int t;
    int player[8] = {1,2,3,4,5,6,7,8};
    int expect_play[50][9] = {0};
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<9; j++) {
            cin >> t;
            expect_play[i][j] = t;
        }
    }
//    cout << 0%9 << ", " << 9%9 << "\n";

    vector<int> v;
    do {
        int sub = 0; int bat[9] = {0};
        int index = 0;
        for (int i = 0; i<N; i++) {
            int record = 0; int out = 0;
            for (int j = 0; j<9; j++) {
                // 1번선수 4번타석
                if (j == 3) {
                    bat[j] = expect_play[i][0];
                } else if (j>3) {
                    bat[j] = expect_play[i][player[j-1]];
                } else {
                    bat[j] = expect_play[i][player[j]];
                }
            }
            while (out < 3) {
                if (bat[index%9] == 0) {
                    out++;
                } else {
                    for (int k = 1; k <= bat[index%9]; k++) {
                        if (record == 0) {
                            record++;
                            continue;
                        }
                        record = record << 1;

                        if (k == 1)
                            record++;
                        if (record >= 8) {
                            sub++;
                            record = record % 8;
                        }
                    }
                }
                index++;
                if (index == 9)
                    index = 0;
            }
        }
        v.push_back(sub);
    } while (next_permutation(begin(player), end(player)));

    cout << *max_element(v.begin(), v.end());

    return 0;
}
