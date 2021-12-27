#include <iostream>
#include <bitset>

using namespace std;

string convert_string(string substr, int index, string converted) {
    string conv_str;
    if (index == 0) {
        if (substr == "ADD" || substr == "ADDC")
            conv_str = "0000";
        else if (substr == "SUB" || substr == "SUBC")
            conv_str = "0001";
        else if (substr == "MOV" || substr == "MOVC")
            conv_str = "0010";
        else if (substr == "AND" || substr == "ANDC")
            conv_str = "0011";
        else if (substr == "OR" || substr == "ORC")
            conv_str = "0100";
        else if (substr == "NOT")
            conv_str = "0101";
        else if (substr == "MULT" || substr == "MULTC")
            conv_str = "0110";
        else if (substr == "LSFTL" || substr == "LSFTLC")
            conv_str = "0111";
        else if (substr == "LSFTR" || substr == "LSFTRC")
            conv_str = "1000";
        else if (substr == "ASFTR" || substr == "ASFTRC")
            conv_str = "1001";
        else if (substr == "RL" || substr == "RLC")
            conv_str = "1010";
        else if (substr == "RR" || substr == "RRC")
            conv_str = "1011";

        if (substr.back() == 'C')
            conv_str += '1';
        else
            conv_str += '0';

        conv_str += '0';
    } else if (index == 1) {
        bitset<3> rD = substr[0] - '0';
        conv_str = rD.to_string();
    } else if (index == 2) {
        bitset<3> rA = substr[0] - '0';
        conv_str = rA.to_string();
    } else if (index == 3) {
        if (converted[4] == '0') {
            bitset<3> rB = substr[0] -'0';
            conv_str = rB.to_string();
            conv_str += '0';
        } else {
            int temp = 0;
            int size = substr.size();
            for (int i = 0; i < size; i++) {
                if (size == 2 && i == 0)
                    temp += (substr[i] - '0') * 10;
                else
                    temp += substr[i] - '0';
            }
            bitset<4> rC = temp;
            conv_str = rC.to_string();
        }
    }
    return conv_str;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i< N; i++) {
        string input;

        string converted;
        for (int j = 0; j < 4; j++) {
            cin >> input;
            converted += convert_string(input, j, converted);
        }
        cout << converted << endl;
    }

    return 0;
}
