#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int N, P;
    for (int test_case = 1; test_case < T; test_case++) {
        cin >> N >> P;

        int div = N/P;
        int mod = N%P;

        vector<int> v;
        for (int i = 0; i < P; i++) {
            v.push_back(div);
        }

        int index = 0;
        while (mod) {
            v[index]++;
            mod--;

            index++;
            if (index == P)
                index = 0;
        }

        long long ret = 1;
        for (int i = 0; i < P; i++) {
            ret *= v[i];
        }
        cout << "#" << test_case << " " << ret << "\n";
    }

    return 0;
}
