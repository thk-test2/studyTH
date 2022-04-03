#include <iostream>
#include <cstring>
#include <vector>

#define endl "\n"
#define MAX 40
using namespace std;

struct Place {
    int id = 0;
    int playtime = 0;
    int point = 0;
};

int N, M, Airport, Answer;
int Distance[MAX][MAX];
bool Visit[MAX];
vector<int> Hotel;
vector<int> Answer_Route;
vector<Place> Tour;

void Initialize()
{
    Hotel.clear();
    Answer_Route.clear();
    Tour.clear();
    Answer = 0;
    memset(Visit, false, sizeof(Visit));
    memset(Distance, 0, sizeof(Distance));
}

void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int a; cin >> a;
            Distance[i][j] = a;
            Distance[j][i] = a;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        char C; cin >> C;
        if (C == 'A') Airport = i;
        else if (C == 'H') Hotel.push_back(i);
        else
        {
            int a, b; cin >> a >> b;
            Tour.push_back({ i, a, b });
        }
    }
}

void DFS(int Cur, int Day, int Satisfy, int Time, int Depth, vector<int>& Route)
{
    if (Cur == Airport && Day == M && Depth != 0)
    {
        if (Satisfy > Answer)
        {
            Answer = Satisfy;
            Answer_Route = Route;
        }
        return;
    }

    bool Flag = false;
    for (int i = 0; i < Tour.size(); i++)
    {
        int Next = Tour[i].id;
        int Play_Time = Tour[i].playtime;
        int nSatisfy = Tour[i].point;
        int Move_Time = Distance[Cur][Next];

        if (Visit[Next] == true || Cur == Next) continue;
        if (Time + Move_Time + Play_Time > 540) continue;

        Flag = true;
        Visit[Next] = true;
        Route.push_back(Next);
        DFS(Next, Day, Satisfy + nSatisfy, Time + Move_Time + Play_Time, Depth + 1, Route);
        Route.pop_back();
        Visit[Next] = false;
    }

    if (Flag == false)
    {
        if (Day == M)
        {
            if (Time + Distance[Cur][Airport] <= 540)
            {
                Route.push_back(Airport);
                DFS(Airport, Day, Satisfy, Time + Distance[Cur][Airport], Depth + 1, Route);
                Route.pop_back();
            }
        }
        else
        {
            for (int i = 0; i < Hotel.size(); i++)
            {
                int Hotel_Num = Hotel[i];
                if (Time + Distance[Cur][Hotel_Num] <= 540)
                {
                    Route.push_back(Hotel_Num);
                    DFS(Hotel_Num, Day + 1, Satisfy, 0, Depth + 1, Route);
                    Route.pop_back();
                }
            }
        }
    }
}

void Solution()
{
    int Start = Airport;
    vector<int> V;
    DFS(Start, 1, 0, 0, 0, V);
}

void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " ";
        cout << Answer << " ";
        if (Answer != 0)
        {
            for (int i = 0; i < Answer_Route.size(); i++)
            {
                cout << Answer_Route[i] << " ";
            }
            cout << endl;
        }
        else cout << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}


// 출처: https://yabmoons.tistory.com/534 [얍문's Coding World..]