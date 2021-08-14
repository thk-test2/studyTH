#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string grade(int score) {
    if (score >= 90)
        return "A";
    else if (score >= 80 && score < 90)
        return "B";
    else if (score >= 70 && score < 80)
        return "C";
    else if (score >= 50 && score < 70)
        return "D";
    else if (score < 50)
        return "F";
}

bool isUnique(vector<int>& scores, int score) {
    std::vector<int> pos;

    for (auto& itr: scores)
        cout << itr << ", ";
    cout << endl;

    int max = 0;
    auto it = max_element(scores.begin(), scores.end());
    while (true)
    {
        if (it != scores.end()) {
            max = *it;
            pos.push_back(distance(begin(scores), it));
            it = find(next(it), end(scores), *it);
        } else {
            break;
        }
    }
    if (score == max && pos.size() == 1)
        return true;

    pos.clear();
    int min = 0;
    it = min_element(scores.begin(), scores.end());
    while (true)
    {
        if (it != scores.end()) {
            min = *it;
            pos.push_back(distance(begin(scores), it));
            it = find(next(it), end(scores), *it);
        } else {
            break;
        }
    }
    if (score == min && pos.size() == 1)
        return true;

    return false;
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    int size = scores.size();
    vector<vector<int>> scores_transed;
    int temp_arr[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp_arr[j][i] = scores[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scores[i][j] = temp_arr[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << scores[i][j] << ", ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        bool unique = isUnique(scores[i], scores[i][i]);
        if (unique) {
            scores[i].erase(scores[i].begin() + i);
        }
        int sum = accumulate(scores[i].begin(), scores[i].end(), 0);
        string temp = grade(sum / scores[i].size());
        answer += temp;
    }

    return answer;
}

int main()
{
    string temp = solution({{100,90,98,88,65},{50,45,99,85,77},{47,88,95,80,67},{61,57,100,80,65},{24,90,94,75,65}});
    cout << temp << endl;

    string temp2 = solution({{50,90},{50,87}});
    cout << temp2 << endl;

    string temp3 = solution({{70,49,90},{68,50,38},{73,31,100}});
    cout << temp3 << endl;
    return 0;
}
