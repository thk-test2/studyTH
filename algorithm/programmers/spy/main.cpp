#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> numbers;
//    sort(clothes.begin(), clothes.end());

//    int index = 0;
//    for (int i = 0; i < clothes.size(); i++) {
//        if (i == 0 && clothes.size()) {
//            numbers.push_back(1);
//            continue;
//        }
//        if (clothes[i][1] == clothes[i-1][1]) {
//            numbers[index]++;
//        }
//        else {
//            numbers.push_back(1);
//            index++;
//        }
//    }
    for (const auto& itr: clothes) {
        numbers[itr[1]]++;
    }

    for (const auto& itr: numbers) {
        answer *= (itr.second+1);
    }

    return answer-1;
}

int main()
{
    cout << "Hello World!" << endl;
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"},
                                      {"blue_sunglasses", "eyewear"},
                                      {"green_turban", "headgear"}};
    cout << solution(clothes) << endl;

    return 0;
}
