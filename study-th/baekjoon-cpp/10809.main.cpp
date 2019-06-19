#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);

    string str;
    cin >> str;

    int alpha[26] = {-1,};
    fill_n(alpha, 26, -1);

    int jari = 0;

    for (char c : str) {
        if (alpha[c-'a'] == -1)
            alpha[c-'a'] = jari;
        jari++;
    }

    for (int i : alpha) {
        cout << i << ' ';
    }

    return 0;
}