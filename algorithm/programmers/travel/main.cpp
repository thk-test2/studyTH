#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visit,
         vector<string>& temp, vector<string>& answer, int count) {
    temp.push_back(from);

    if (count == tickets.size()) {
        answer = temp;
        return true;
    }

    for (int i = 0; i< tickets.size(); i++) {
        if (tickets[i][0] == from && visit[i] == false) {
            visit[i] = true;
            bool success = dfs(tickets[i][1], tickets, visit, temp, answer, ++count);

            if (success)
                return true;
            visit[i] = false;
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer,temp;
    vector<bool> visit(tickets.size(), false);

    sort(tickets.begin(), tickets.end());

    dfs("ICN", tickets, visit, temp, answer, 0);

    return answer;
}

int main()
{
    solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"},
            {"ATL", "ICN"}, {"ATL","SFO"}});
//    solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
    return 0;
}

//vector<string> solution(vector<vector<string>> tickets) {
//    vector<string> answer;

//    sort(tickets.begin(), tickets.end());

//    for (const auto& itr: tickets)
//        cout << itr[0] << ", " << itr[1] << endl;

//    map<string, int> numbers;

//    int index = 0;
//    for (int i = 0; i< tickets.size(); i++) {
//        if ((i == 0) || (tickets[i][0] != tickets[i-1][0])) {
//            numbers.insert(make_pair(tickets[i][0], index));
//            index++;
//            continue;
//        }
//    }

////    cout << numbers.find("ATL")->second << endl;
////    cout << numbers.find("ICN")->second << endl;
////    cout << numbers.find("SFO")->second << endl;

//    vector<vector<int>> converted;
//    for (int i = 0; i < numbers.size(); i++)
//        converted.push_back({});

//    for (int i = 0; i< tickets.size(); i++) {
//        converted[numbers.find(tickets[i][0])->second].push_back(
//                    numbers.find(tickets[i][1])->second);
//    }
//    int next = converted[numbers.find("ICN")->second].front();
//    while (true) {
//    }

////    for (const auto & itr: converted)
////        cout << itr[0] << ", " << itr[1] << endl;
//    return answer;
//}
