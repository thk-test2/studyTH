#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();

    for (int i = 0; i< n ; i++) {
        answer.push_back(0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            answer[i]++;
            if (prices[i] > prices[j])
                break;

        }
    }

    for (auto &itr: answer) {
        cout << itr << ", ";
    }
    return answer;
}

int main()
{

    cout << "Hello World!" << endl;
    vector<int> test = {1, 2, 3, 2, 3};
    solution(test);
    return 0;
}
