#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 1, mid = 0, removeCnt = 0, lastRock = 0, gap = 0;
    int start = 1;
    int end = distance;
    sort(rocks.begin(), rocks.end());

    while (start <= end) {
        mid = (start + end) / 2;
        gap = 0;
        lastRock = 0;
        removeCnt = 0;

        for (int i = 0; i <= rocks.size() ; i++) {
            if (i == rocks.size())
                gap = distance - lastRock;
            else
                gap = rocks[i] - lastRock;

            if (gap < mid) {
                removeCnt++;
            } else if ( i != rocks.size() ) {
                lastRock = rocks[i];
            }
        }

        if (removeCnt > n) {
            end = mid - 1;
        } else {
            start = mid + 1;
            answer = max(mid, answer);
        }
    }
    return answer;
}

int main()
{
    cout << solution(25, {2, 14, 11, 21, 17}, 2) << endl;
    return 0;
}
