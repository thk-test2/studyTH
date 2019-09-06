#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>

using namespace std;

struct IGuessor
{
    virtual void guess(int *x, int *y, int *z) = 0;
    virtual ~IGuessor() {}
};

class BaseBallGame
{
    typedef tuple<int, int, int> INPUT;
    typedef tuple<int, int> RESULT;
    vector<pair<INPUT, RESULT> > v;
    IGuessor* pVal = 0;
public:
    BaseBallGame() { srand((unsigned)time(0)); }
    
    void setGuessor(IGuessor *p) { pVal = p; }

    void run() 
    {
        while(1)
        {
            //-----------------------------------------------
            // 이전의 결과가 담긴 vector v를 참고해서
            // 사용자가 생각한 숫자를 예측해냅니다.
            // 현재 구현은 무조건 랜덤입니다.
            int x = 0, y = 0, z = 0;
            pVal->guess(&x, &y, &z);
            //--------------------------------------
            cout << "당신이 생각한 숫자는" << x 
                << ", " << y <<", " << z << " 입니까?" << endl;
            int strike = 0, ball = 0;
            cout <<"strike 갯수: ";
            cin >>strike;
            if(strike == 3)
            {
                cout << "성공!" << endl;
                break;
            }
            // ball 자동 입력
            ball = 3-strike;
            cout << "ball 갯수: " << ball << endl;
            //--------------------------------------
            // 입력된 결과(strike, ball)을 기록 해두었다가
            // 다음수를 예측할때 사용합니다.
            v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
            dump();
        }
    }
    // 필요하신 분을 위해 참고용으로 만든 함수입니다.
    void dump()
    {
        printf("-------------------------------\n");
        printf("입력\n");
        for(auto& p  : v) // p는 pair<INPUT, RESULT> 입니다.
        {
            printf(" %d %d %d : %d %d\n",
                get<0>(p.first), get<1>(p.first), get<2>(p.first),
                get<0>(p.second), get<1>(p.second));
        }
        printf("-------------------------------\n");
    }
};

class RandomGuessor : public IGuessor
{
public:
    virtual void guess(int *x, int *y, int *z) {
        do {
                *x = rand() % 9 + 1;
                *y = rand() % 9 + 1;
                *z = rand() % 9 + 1;
            } while(x == y || y == z || x == z);
    }
};

int main(void)
{
    BaseBallGame bbg;
    RandomGuessor rg;
    bbg.setGuessor(&rg);

    bbg.run();
}
