#include <iostream>
#include <ctime>

using namespace std;

// 0~9 사이의 난수 얻기
int frand() { return rand() %10; }

class URandom
{
    char history[10];
public:
    URandom()
    {
        for (int i = 0; i< 10; i++)
            history[i] = 0;
        srand(time(0));
    }

    int operator()()
    {
        int n = -1;
        do
        {
            n = rand() % 10;
        } while (history[n] == 1);
        history[n] = 1;

        return n;
    }
};

int main()
{
    URandom orand;

    cout << orand() << endl;
    cout << orand() << endl;
    cout << orand() << endl;
    cout << orand() << endl;
};
