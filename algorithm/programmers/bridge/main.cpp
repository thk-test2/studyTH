#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<pair<int, int>> bridge;

    while (true) {
        answer++;
        for (auto & itr: bridge) {
            itr.second--;
        }
        if (!bridge.empty() && bridge.begin()->second == 0) {
            bridge.erase(bridge.begin());
            if (bridge.size() + truck_weights.size() == 0)
                break;
        }
        if (!truck_weights.empty() && (bridge.size() < bridge_length))
        {
            int part_sum = accumulate(bridge.begin(), bridge.end(), 0,
                                  [](auto &a, auto &b){return a + b.first;});
            int next = *truck_weights.begin();
            if (part_sum + next <= weight) {
                bridge.push_back(make_pair(next, bridge_length));
                if (!truck_weights.empty())
                    truck_weights.erase(truck_weights.begin());
            }
        }
        cout << answer << ", " << bridge.size() << ", " << truck_weights.size() << endl;
    }
    return answer;
}

int main()
{
//    vector<int>test = {7, 4, 5, 6};
//    int ret = solution(2, 10, test);
    vector<int>test = {10,10,10,10,10,10,10,10,10,10};
    int ret = solution(100, 100, test);

    cout << "Hello World!: " << ret << endl;
    return 0;
}
