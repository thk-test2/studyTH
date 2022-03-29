#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> maxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;

	int N, t;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		
		// 1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
		// 2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
		//    이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
		if (maxQ.empty())
			maxQ.push(t);
		else if (maxQ.size() == minQ.size())
			maxQ.push(t);
		else
			minQ.push(t);

		if (!maxQ.empty() && !minQ.empty()) {
			if (!(maxQ.top() <= minQ.top())) {
				int a = maxQ.top(); maxQ.pop();
				int b = minQ.top(); minQ.pop();
				minQ.push(a);  maxQ.push(b);
			}
		}

		/*if (!maxQ.empty()) {
			if (maxQ.size() == minQ.size()) {
				if (minQ.top() <= t) {
					int moving = minQ.top();
					minQ.pop();
					minQ.push(t);
					maxQ.push(moving);
				}
				else {
					maxQ.push(t);
				}
			}
			else {
				if (maxQ.top() >= t) {
					int moving = maxQ.top();
					maxQ.pop();
					maxQ.push(t);
					minQ.push(moving);
				}
				else {
					minQ.push(t);
				}
			}
		}
		else {
			maxQ.push(t);
		}*/
		cout << maxQ.top() << "\n";
	}

	return 0;
}