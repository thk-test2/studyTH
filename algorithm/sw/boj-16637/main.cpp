#include <iostream>
#include <vector>

using namespace std;

int n, answer = -2147000000;
string str;

int calculate(int a, int b, char op) {
    switch(op) {
    case '+':
        a += b;
        break;
    case '-':
        a -= b;
        break;
    case '*':
        a *= b;
        break;
    }
    return a;
}

void dfs(int idx, int cur) {
    if (idx >= n) {
        answer = max(answer, cur);
        return;
    }

    char op = (idx == 0) ? '+' : str[idx - 1];

    if (idx + 2 < n) {
        int bracket = calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        dfs(idx + 4, calculate(cur, bracket, op));
    }
    dfs(idx + 2, calculate(cur, str[idx] - '0', op));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> str;
    dfs(0, 0);

    cout << answer;
    return 0;
}
