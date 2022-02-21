#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> pos(n);
        for (int i = 0; i < n; i++)
        {
            int xPos;
            cin >> xPos;
            pos[i].first = xPos;
        }

        for (int i = 0; i < n; i++)
        {
            int weight;
            cin >> weight;
            pos[i].second = weight;
        }

        cout << fixed;
        cout.precision(10);
        cout << "#" << tc << " ";
        for (int idx = 0; idx < n - 1; idx++)
        {
            double lo = pos[idx].first;
            double hi = pos[idx + 1].first;
            double mid = 0.0;
            int cnt = 101;
            while (cnt--)
            {
                mid = (lo + hi) / 2;

                double left = 0.0, right = 0.0;
                for (int i = 0; i <= idx; i++)
                {
                    double d = mid - pos[i].first;
                    left += pos[i].second / (d * d);
                }

                for (int i = idx + 1; i < n; i++)
                {
                    double d = pos[i].first - mid;
                    right += pos[i].second / (d * d);
                }

                if (right > left) hi = mid;
                else lo = mid;
            }
            cout << mid << " ";
        }
        cout << '\n';
    }
    return 0;
}