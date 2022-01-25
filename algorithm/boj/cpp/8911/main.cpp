#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string cmd;

    for (int i = 0; i < T; i++) {
        cin >> cmd;
        pair<int, int> pos = {0, 0};
        vector<pair<int, int>> mov = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}, };
        int index = 0;

        pair<int, int> x_range = {0, 0};
        pair<int, int> y_range = {0, 0};

        for (const auto& itr: cmd) {
            if (itr == 'F') {
                pos.first += mov[index].first;
                pos.second += mov[index].second;
            } else if (itr == 'B') {
                pos.first -= mov[index].first;
                pos.second -= mov[index].second;
            } else if (itr == 'L') {
                index = (index+1) % 4;
            } else if (itr == 'R') {
                index = (index == 0 ? 3 : (index-1) % 4);
            }
            x_range.first = min(x_range.first, pos.first);
            x_range.second = max(x_range.second, pos.first);

            y_range.first = min(y_range.first, pos.second);
            y_range.second = max(y_range.second, pos.second);
//            cout << pos.first << ", " << pos.second << endl;
        }
//        cout << x_range.first << ", " << x_range.second << ", "
//             << y_range.first << ", " << y_range.second << endl;
        cout << (x_range.second - x_range.first) * (y_range.second - y_range.first) << endl;
    }

    return 0;
}
