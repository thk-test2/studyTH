#include <iostream>
#include <map>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    map<int, string> m = { {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"},
                           {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"},
                           {8, "eight"}, {9, "nine"}};
    map<string, int> m2;

    for (int i = M; i <= N; i++) {
        string temp = "";

        int ten = i/10;
        if (ten != 0) {
            temp += m[ten] + " ";
        }

        int one = i%10;
        temp += m[one];

        m2.insert(make_pair(temp, ten*10+one));
    }

    int cnt = 0;
    for (auto& itr: m2) {
        cout << itr.second << " ";
        if (cnt++ % 10 == 9)
            cout << endl;
    }

    return 0;
}
