#include <iostream>

//조합을 구현할 때에는 2개의 매개변수를 이용해서 구현할 수 있다.
//1. Idx변수 : 시작점을 결정해주는 변수이다. 우리는 Idx를 시작점으로 삼는 순간, Idx이전에 나온 원소는 쳐다도
//   보지 않을 것이다.
//2. Cnt변수 : 우리가 현재 뽑은 원소의 갯수를 결정해주는 변수이다. 현재 뽑은 원소의 갯수가 우리가 최종적으로
//   뽑고자 하는 원소의 갯수와 일치한다면, 그 다음 프로세스를 진행하면 된다.

//출처: https://yabmoons.tistory.com/99 [얍문's Coding World..]

#define MAX 5

using namespace std;

bool selected[MAX] = {false};
int arr[MAX];
int N = 3;

void combi(int index, int cnt) {
    if (cnt == 3) {
        cout << "{ ";
        for (int i = 0; i < MAX; i++) {
            if (selected[i])
                cout << arr[i] << " ";
        }
        cout << "}" << "\n";
        return;
    }
    for (int i = index; i < MAX; i++) {
        if (selected[i])
            continue;
        selected[i] = true;
        combi(i, cnt+1);
        selected[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < MAX; i++) {
        arr[i] = i+1;
    }
    combi(0, 0);
    return 0;
}
