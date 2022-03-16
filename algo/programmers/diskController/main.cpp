#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int size = jobs.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> minq;
    sort(jobs.begin(), jobs.end());
    int currentTime = 0, waitTime = 0, i = 0;

    while (!minq.empty() || (i < jobs.size())) {
        if ((i < jobs.size()) && jobs[i][0] <= currentTime) {
            minq.push(make_pair(jobs[i][0], jobs[i][1]));
            i++;
            continue;
        }
        if (!minq.empty()) {
            currentTime += minq.top().second;
            waitTime += currentTime - minq.top().first;
            minq.pop();
        } else {
            currentTime = jobs[i][0];
        }
    }
    return waitTime / size;
}

int main()
{
    cout << solution({{0, 3}, {1, 9}, {2, 6}}) << endl;
//    solution({{0, 3}, {0, 2}, {1, 9}, {2, 6}});
    return 0;
}
