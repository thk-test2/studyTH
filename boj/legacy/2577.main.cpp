#include <iostream>

using namespace std;

int main () {
    cin.tie(nullptr);

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    int d = a*b*c;

    string str = to_string(d);
    
    int count[10] = {0,};

    for (char c : str) {
        switch (c)
        {
        case '0':
            ++count[0];
            break;
        case '1':
            ++count[1];
            break;
        case '2':
            ++count[2];
            break;
        case '3':
            ++count[3];
            break;
        case '4':
            ++count[4];
            break;
        case '5':
            ++count[5];
            break;
        case '6':
            ++count[6];
            break;
        case '7':
            ++count[7];
            break;
        case '8':
            ++count[8];
            break;
        case '9':
            ++count[9];
            break;
        }
    }
    for (int i = 0 ; i<10 ; i++) {
        cout << count[i] << '\n';
    }

    return 0;
}