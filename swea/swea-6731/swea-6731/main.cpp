#include<iostream>
#include<cstring>

#define endl "\n"
#define MAX 1000
using namespace std;

int N, Answer;
char MAP[MAX][MAX];
int Garo[MAX];
int Sero[MAX];

void Initialize()
{
    memset(Garo, 0, sizeof(Garo));
    memset(Sero, 0, sizeof(Sero));
    Answer = 0;
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'B')
            {
                Garo[i]++;
                Sero[j]++;
            }
        }
    }
}

void Solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int Cnt = Garo[i] + Sero[j];
            if (MAP[i][j] == 'B') Cnt--;
            if (Cnt % 2 == 1) Answer++;
        }
    }
}

void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}

// ÃâÃ³: https://yabmoons.tistory.com/426 [¾å¹®'s Coding World..]