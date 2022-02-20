#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int A[N+1][M+1];
    int t;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> t;
            A[i][j] = t;
        }
    }

    vector<tuple<int, int, int>> vt;
    int r, c, s;
    for (int k = 1; k <= K; k++) {
        cin >> r >> c >> s;
        vt.push_back(make_tuple(r, c, s));
    }
    sort(vt.begin(), vt.end());

    int minimum = INT_MAX;
    int T[N+1][M+1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            T[i][j] = A[i][j];
        }
    }
    do {
        int si, sj;
        int ei, ej;
        for (int i = 0; i < vt.size(); i++) {
            int r = get<0>(vt[i]);
            int c = get<1>(vt[i]);
            int s = get<2>(vt[i]);

            si = r-s, sj = c-s;
            ei = r+s, ej = c+s;

            while (si != ei) {
                int temp = A[si][sj];
                for (int j = sj+1; j <= ej; j++) {
                    swap(A[si][j], temp);
                }
                for (int i = si+1; i <= ei; i++) {
                    swap(A[i][ej], temp);
                }
                for (int j = ej-1; j >= sj; j--) {
                    swap(A[ei][j], temp);
                }
                for (int i = ei-1; i >= si; i--) {
                    swap(A[i][sj], temp);
                }
                si++; sj++;
                ei--; ej--;
            }
        }

        for (int i = 1; i <= N; i++) {
            int sum = 0;
            for (int j = 1; j <= M; j++) {
                sum += A[i][j];
            }
            minimum = min(minimum, sum);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                A[i][j] = T[i][j];
            }
        }
    } while (next_permutation(vt.begin(), vt.end()));

    cout << minimum;

    return 0;
}
