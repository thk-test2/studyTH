#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        cout << "#" << i << " " << t/3 << "\n";
    }
    return 0;
}
