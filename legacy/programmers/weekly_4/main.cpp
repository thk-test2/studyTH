#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <queue>

using namespace std;

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

struct cmp {
    //연산자 오버로딩
    bool operator()(pair<int, string>&a, pair<int, string>&b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }
};

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    vector<vector<pair<string, int>>> total = {{},{},{},{},{}};

    for (int i = 0; i < table.size(); i++) {
        vector<string> elements = split(table[i], ' ');

        for (int j = 0; j < elements.size(); j++) {
            total[i].push_back(make_pair(elements[j], 6-j));
        }
    }

    priority_queue<pair<int,string>,vector<pair<int,string>>, cmp> pq;
    for (int i = 0; i < table.size(); i++) {
        int partial_sum = 0;
        for (int j = 0; j < languages.size(); j++) {

            string temp = languages[j];
            auto itr = find_if(total[i].begin(), total[i].end(), [&temp](const pair<string,int>& element) {
                    return element.first == temp;
            });
            if (itr != total[i].end()) {
                partial_sum += itr->second * preference[j];
            }
        }
        pq.push(make_pair(partial_sum, total[i][0].first));
    }

    return pq.top().second;
}

int main()
{
    string result = solution({"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"},
                             {"PYTHON", "C++", "SQL"}, {7, 5, 5});
//    string result = solution({"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"},
//                             {"JAVA", "JAVASCRIPT"}, {7, 5});
    cout << result << endl;
    return 0;
}
