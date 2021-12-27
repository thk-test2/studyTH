#include <iostream>

using namespace std;

int main () {
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;

    int adder = 0;
    int sum[n] = {0,};
    int i=0;

    cin.clear();
    cin.ignore(__INT_MAX__, '\n');

    while(n>0) {
        getline(cin, str);
        adder = 0;

        for (char c : str) {
            switch (c)
            {
            case 'O':
                ++adder;
                sum[i] += adder;
                break;
        
            default:
                adder = 0;
                break;
            }
        }   
        n--;
        i++;
    } 

    for (int c : sum)
        cout << c << '\n';

    return 0;
}