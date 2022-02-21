#include<iostream>
 
#define NOTMAKED 9999
 
using namespace std;
 
int n, o, m, w;
int answer = 0;
bool cantouch[10];
bool oper[5];
int number_cnt[1000];
int maked[1000];
 
void dfs(int total, int depth) {
    if (depth >= m)
        return; 
    if (total == w) {
        if(answer > depth + 1)
            answer = depth + 1;
    }
    for (int i = 1; i < 1000; i++) {
        if (number_cnt[i] == NOTMAKED) continue;
 
        for (int j = 1; j < 5; j++) {
            if (!oper[j]) continue;
            int nxttotal = total;
 
            if (j == 1) {
                nxttotal += i;
            } else if (j == 2) {
                nxttotal -= i;
            } else if (j == 3) {
                nxttotal *= i;
            } else if (j == 4) {
                nxttotal /= i;
            }
            if (nxttotal < 0 || nxttotal > 999) continue;
            if (maked[nxttotal] > depth + number_cnt[i] + 1) {
                maked[nxttotal] = depth + number_cnt[i] + 1;
                dfs(nxttotal, maked[nxttotal]);
            }
        }
 
    }
}
 
 
void init() {
    for (int i = 0; i < 10; i++) 
        cantouch[i] = false;
    for (int i = 0; i < 5; i++)
        oper[i] = false;
    for (int i = 0; i < 1000; i++) {
        number_cnt[i] = NOTMAKED;
        maked[i] = NOTMAKED;
    }
 
    answer = NOTMAKED;
}
 
void maker(int num, int depth) {
    if (depth == 4) return;
 
    for (int i = 0; i < 10; i++) {
        if (!cantouch[i]) continue;
 
        int maked = num * 10 + i;
 
        if (maked < 0 || maked > 999) continue;
 
        if (number_cnt[maked] > depth + 1) {
            number_cnt[maked] = depth + 1;
            maker(maked, depth + 1);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> n >> o >> m;
         
        init();
 
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            cantouch[num] = true;
        }
 
        for (int i = 0; i < 10; i++) {
            if (!cantouch[i]) continue;
            number_cnt[i] = 1;
            maker(i, 1);
        }
 
        for (int i = 0; i < o; i++) {
            int op;
            cin >> op;
            oper[op] = true;
        }
        cin >> w;
 
        if (number_cnt[w] == NOTMAKED) {
            for (int i = 1; i < 1000; i++) {
                if (number_cnt[i] == NOTMAKED) continue;
 
                dfs(i, number_cnt[i]);
            }
        }
        else {
            answer = number_cnt[w];
        }
 
        if (answer == NOTMAKED) answer = -1;
        cout << "#"<<test<<" " << answer << "\n";
    }
 
    return 0;
}