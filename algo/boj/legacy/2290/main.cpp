#include <iostream>

using namespace std;

int main()
{
    int s;
    cin >> s;

    string n;
    cin >> n;

    for (int i = 0; i < 2*s+3 ; i++) {
        string line;
        for (int k = 0; k < (s+3) * n.size() ; k++) {
            line.push_back(' ');
        }
        for (int j = 0; j < s+2 ; j++) {
            if (i == 0 || i == s+1 || i == 2*s+2) {
                for (int k = 0; k < n.size() ; k++) {
                    if (n[k] == '0') {
                        if (i == 0 || i == 2*s+2) {
                            if (j == 0 || j == s+1)
                                line[j+(s+3)*k] = ' ';
                            else
                                line[j+(s+3)*k] = '-';
                        }
                    }
                    else if (n[k] == '2' || n[k] == '3' || n[k] == '5' || n[k] == '6' || n[k] == '8' || n[k] == '9') {
                        if (j == 0 || j == s+1)
                            line[j+(s+3)*k] = ' ';
                        else
                            line[j+(s+3)*k] = '-';
                    }
                    else if (n[k] == '4') {
                        if (i == s+1) {
                            if (j == 0 || j == s+1)
                                line[j+(s+3)*k] = ' ';
                            else
                                line[j+(s+3)*k] = '-';
                        }
                    }
                    else if (n[k] == '7') {
                        if (i == 0) {
                            if (j == 0 || j == s+1)
                                line[j+(s+3)*k] = ' ';
                            else
                                line[j+(s+3)*k] = '-';
                        }
                    }
                }
            } else {
                for (int k = 0; k < n.size() ; k++) {
                    if (n[k] == '1' || n[k] == '3' || n[k] == '7') {
                        if (i > 0 && i < s+1 && j == s+1)
                            line[j+(s+3)*k] = '|';
                        else if (i > s+1 && i < 2*s+2 && j == s+1)
                            line[j+(s+3)*k] = '|';
                        else
                            line[j+(s+3)*k] = ' ';
                    }
                    else if (n[k] == '2') {
                        if (i > 0 && i < s+1 && j == s+1)
                            line[j+(s+3)*k] = '|';
                        else if (i > s+1 && i < 2*s+2 && j == 0)
                            line[j+(s+3)*k] = '|';
                        else
                            line[j+(s+3)*k] = ' ';
                    }
                    else if (n[k] == '4' || n[k] == '9') {
                        if (i > 0 && i < s+1 && (j==0 || j == s+1))
                            line[j+(s+3)*k] = '|';
                        else if (i > s+1 && i < 2*s+2 && j == s+1)
                            line[j+(s+3)*k] = '|';
                        else
                            line[j+(s+3)*k] = ' ';
                    }
                    else if (n[k] == '5') {
                        if (i > 0 && i < s+1 && j == 0)
                            line[j+(s+3)*k] = '|';
                        else if (i > s+1 && i < 2*s+2 && j == s+1)
                            line[j+(s+3)*k] = '|';
                        else
                            line[j+(s+3)*k] = ' ';
                    }
                    else if (n[k] == '6') {
                        if (i > 0 && i < s+1 && j == 0)
                            line[j+(s+3)*k] = '|';
                        else if (i > s+1 && i < 2*s+2 && (j==0 || j == s+1))
                            line[j+(s+3)*k] = '|';
                        else
                            line[j+(s+3)*k] = ' ';
                    }
                    else if (n[k] == '8' || n[k] == '0') {
                        if (i > 0 && i < s+1 && (j==0 || j == s+1))
                            line[j+(s+3)*k] = '|';
                        else if (i > s+1 && i < 2*s+2 && (j==0 || j == s+1))
                            line[j+(s+3)*k] = '|';
                        else
                            line[j+(s+3)*k] = ' ';
                    }
                }
            }
        }
        cout << line << endl;
    }

    return 0;
}
