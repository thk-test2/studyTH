#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string convert_string(string substr) {
    string conv_str;
    string variable_name;
    bool operator_end = false;

    for (string::reverse_iterator rit = substr.rbegin() + 1 ;
         rit != substr.rend() ; rit++) {
        char temp = *rit;

        if (temp == '*' || temp == '&') {
            conv_str += temp;
        }
        else if (temp == ']') {
            conv_str += "[]";
            rit++;
        } else {
            if (!operator_end) {
                operator_end = true;
                conv_str = conv_str + " ";
                variable_name += temp;
            } else {
                variable_name += temp;
            }
        }
    }
    reverse(variable_name.begin(), variable_name.end());
    conv_str += variable_name + ";";
    return conv_str;
}

int main()
{
    string input;
    getline(cin, input);

    vector<string> converted;
    int previous = 0, current;
    string common;

    do {
        current = input.find(' ', previous);
        string substr = input.substr(previous, current - previous);
        if (previous == 0) {
            common = substr;
        } else {
            converted.push_back(common + convert_string(substr));
        }
        previous = current + 1;
    } while (current != string::npos);

    for (const auto& itr : converted) {
        cout << itr << endl;
    }
    return 0;
}
