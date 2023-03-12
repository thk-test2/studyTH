#include <iostream>

#define MAX 5

using namespace std;

int selected[MAX] = {0};
int arr[MAX];
int N = 3;

void combi(int cnt) {
    if (cnt == 3) {
        cout << "{ ";
        for (int i = 0; i < 3; i++) {
            cout << selected[i] << " ";
        }
        cout << "}" << "\n";
        return;
    }
    for (int i = 0; i < MAX; i++) {
        selected[cnt] = arr[i];
        combi(cnt+1);
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
    combi(0);
    return 0;
}
