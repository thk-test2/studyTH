#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>&numbers, int target, int& answer, int index = -1, int tempSum = 0) {
    if (index == numbers.size() - 1) {
        if (tempSum == target)
            answer++;
        return;
    }
    index++;
//    cout << index << ", " << answer << ", " << tempSum << endl;
    dfs(numbers, target, answer, index, tempSum + numbers[index]);
    dfs(numbers, target, answer, index, tempSum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers, target, answer);

    return answer;
}

int main()
{
    cout << solution({1, 1, 1, 1, 1}, 3) << endl;
    return 0;
}
