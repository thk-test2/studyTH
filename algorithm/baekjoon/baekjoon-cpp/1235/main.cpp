#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> v;
    vector<string> subv;

    string n;
    for (int i = 0; i<N; i++) {
        cin >> n;
        v.push_back(n);
        subv.push_back("");
    }

    int k = 1;
    int size = v.front().size();
    while (1) {
        for (int i = 0; i<N; i++) {
            subv[i] += v[i].at(size-k);
        }

        set<string> s;
        bool dupl = false;
        for (auto& itr: subv) {
            auto ret = s.insert(itr);

            if (!ret.second) {
                dupl = true;
                break;
            }
        }
        if (!dupl)
            break;
        k++;
    }
    cout << k;

    return 0;
}
