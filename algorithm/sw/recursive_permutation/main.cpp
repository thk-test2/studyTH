#include <iostream>

#define MAX 5

using namespace std;

bool selected[MAX] = {false};
int selected_n[MAX];
int arr[MAX];
int N = 3;

void permu(int cnt) {
    if (cnt == 3) {
        cout << "{ ";
        for (int i = 0; i < N; i++)
            cout << selected_n[i] << " ";
        cout << "}" << "\n";
    }
    for (int i = 0; i < MAX; i++) {
        if (selected[i])
            continue;
        selected[i] = true;
        selected_n[cnt] = arr[i];
        permu(cnt+1);
//        v.pop_back(); // 123 ~ 125 리턴하고 돌아와서 2를 빼고, 3을 넣음. 다음 재귀에 132.
        selected[i] = false;
    }
}

int main()
{
    for (int i = 0; i < MAX; i++) {
        arr[i] = i+1;
    }
    permu(0);
    return 0;
}
