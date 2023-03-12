#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAX_TEAM_COUNT = 6;
vector<int> win[4], draw[4], lose[4];
int matches[15][2];
bool isEndGame = false;

void backtracking(int i, int matchCount, int size) {
    if (isEndGame)
        return;
    if (matchCount == size) {
        isEndGame = true;
        return;
    }
    int myTeam = matches[matchCount][0];
    int enemyTeam = matches[matchCount][1];

    // 승 패
    if (win[i][myTeam] > 0 && lose[i][enemyTeam] > 0) {
        win[i][myTeam]--; lose[i][enemyTeam]--;
        backtracking(i, matchCount+1, size);
        win[i][myTeam]++; lose[i][enemyTeam]++;
    }
    // 무 무
    if (draw[i][myTeam] > 0 && draw[i][enemyTeam] > 0) {
        draw[i][myTeam]--; draw[i][enemyTeam]--;
        backtracking(i, matchCount+1, size);
        draw[i][myTeam]++; draw[i][enemyTeam]++;
    }
    // 패 승
    if (lose[i][myTeam] > 0 && win[i][enemyTeam] > 0) {
        lose[i][myTeam]--; win[i][enemyTeam]--;
        backtracking(i, matchCount+1, size);
        lose[i][myTeam]++; win[i][enemyTeam]++;
    }
}

int main()
{
    int index = 0;
    for (int i = 0; i < MAX_TEAM_COUNT-1 ; i++) {
        for ( int j = i+1; j < MAX_TEAM_COUNT; j++) {
            matches[index][0] = i;
            matches[index][1] = j;
            index++;
        }
    }

    int n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 18; j++) {
            cin >> n;
            switch(j%3) {
            case 0:
                win[i].push_back(n);
                break;
            case 1:
                draw[i].push_back(n);
                break;
            case 2:
                lose[i].push_back(n);
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int winCnt = accumulate(win[i].begin(), win[i].end(), 0);
        int drawCnt = accumulate(draw[i].begin(), draw[i].end(), 0);
        int loseCnt = accumulate(lose[i].begin(), lose[i].end(), 0);

        bool cont = false;
        for (int j = 0; j < 6; j++) {
            int eachCnt = win[i][j] + draw[i][j] + lose[i][j];
            if (eachCnt != 5) {
                cout << "0 ";
                cont = true;
                break;
            }
        }
        if (cont)
            continue;

        backtracking(i, 0, 15);
        isEndGame ? cout << "1 "
                            : cout << "0 ";
        isEndGame = false;
    }

    return 0;
}
