#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string N;
    cin >> N;

    int visited[10] = {0,};

    for (auto& itr : N) {
        if (itr == '6' || itr == '9') {
            if (visited[6] < visited[9]) {
                visited[6]++;
                continue;
            }
            else if (visited[6] > visited[9]) {
                visited[9]++;
                continue;
            }
        }
        visited[itr-'0']++;
    }

    cout << *max_element(begin(visited), end(visited));

    return 0;
}
