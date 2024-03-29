#include <cstdio>
#include <cstring>

int n, r[100003];
char a[100003], s[20005][5];

int isone(int x) {
    for (int i = 0; i < 5; i++)
        if (s[x][i] == '.' || s[x+1][i] == '#') return 0;
    return 1;
}

int count(int x) {
    int ret = 0;
    for (int i = x; i < x+3; i++)
        for (int j = 0; j < 5; j++)
            ret += s[i][j] == '.';
    return ret;
}

int main() {
    scanf("%d %s", &n, a);
    for (int i = 0; i < n; i++) {
        s[i%(n/5)][i/(n/5)] = a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n / 5; i++) {
        if (s[i][0] == '.') continue;
        if (isone(i)) {
            r[cnt++] = 1, i++;
            continue;
        }
        int ret = count(i);
        switch (ret) {
        case 2:
            r[cnt] = 8;
            break;
        case 3:
            if (s[i+2][1] == '.') r[cnt] = 6;
            else if (s[i][3] == '.') r[cnt] = 9;
            else r[cnt] = 0;
            break;
        case 4:
            if (s[i+2][1] == '.') r[cnt] = 5;
            else if (s[i][3] == '.') r[cnt] = 3;
            else r[cnt] = 2;
            break;
        case 6:
            r[cnt] = 4;
            break;
        case 8:
            r[cnt] = 7;
        }
        cnt++, i+=2;
    }

    for (int i = 0; i < cnt; i++) {
        printf("%d", r[i]);
    }

    return 0;
}
