#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int solution(multiset<int>& scores, int newScore, int bound) {
    int rank = 0;

    if (scores.size() < bound) {
        scores.insert(newScore);
    } else {
        auto itr = find_if(begin(scores), end(scores), [newScore](int a){return a < newScore;});
        if (itr != end(scores)) {
            scores.erase(itr);
            scores.insert(newScore);
        } else
            return -1;
    }
    set<int>::reverse_iterator rit;
    for (rit = scores.rbegin(); rit != scores.rend(); rit++) {
        rank++;
        if (*rit == newScore)
            break;
    }
    return rank;
}

int main()
{
    int N, newScore, bound, t;
    multiset<int> scores;
    cin >> N >> newScore >> bound;

    for (int i = 0; i < N; i++) {
        cin >> t;
        scores.insert(t);
    }
    cout << solution(scores, newScore, bound);

    return 0;
}
