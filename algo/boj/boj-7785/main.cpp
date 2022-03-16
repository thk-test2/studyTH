#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    set<string, greater<string>> s;
    string name, cmd;
    for (int i = 0; i < N; i++) {
        cin >> name >> cmd;
        if (cmd == "enter") {
            s.insert(name);
        } else {
            auto itr = s.find(name);
            if (itr != s.end()) {
                s.erase(itr);
            }
        }
    }
    for (auto& itr: s)
        cout << itr << "\n";

    return 0;
}
