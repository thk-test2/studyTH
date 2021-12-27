#include <iostream>
#include <set>

using namespace std;

// O(N)으로 시간초과
// O(log(N)) 방식: set, binary_search로 가능

int main()
{
    int nA, nB, n;
    cin >> nA >> nB;
    set<int> A;

    for (int i=0; i<nA; i++) {
        cin >> n;
        A.insert(n);
    }
    for (int i=0; i<nB; i++) {
        cin >> n;
        if (A.empty()) {
            cout << 0;
            return 0;
        }
        auto temp = A.find(n);
        if (temp != A.end())
            A.erase(temp);
    }

    cout << A.size() << endl;
    for (const auto& itr : A)
            cout << itr << " ";

    return 0;
}
