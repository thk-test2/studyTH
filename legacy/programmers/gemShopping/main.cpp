#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, INT_MAX};
    unordered_map<string, int> gm, tmp;

    for (auto& itr: gems)
        gm[itr]++;

    int gnum = gm.size();
    int left = 0, right = 0;

    while (right < gems.size()) {
        tmp[gems[right]]++;
        right++;

        if (tmp.size() == gnum) {
            while (left < right) {
                if (tmp[gems[left]] <= 1)
                    break;
                tmp[gems[left]]--;
                left++;
            }
            if (answer[1] - answer[0] + 1 > right - left)
                answer = {left+1, right};
        }
    }
    return answer;
}

int main()
{
//    vector<int> ret = solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
//    vector<int> ret = solution({"AA", "AB", "AC", "AA", "AC"});
//    vector<int> ret = solution({"XYZ", "XYZ", "XYZ"});
//    vector<int> ret = solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"});
    vector<int> ret = solution({"DIA", "EM", "EM", "RUB", "DIA"});
    for (const auto& itr: ret)
        cout << itr << ", ";
    return 0;
}
