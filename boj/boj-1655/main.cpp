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
		
		// 1. �ִ� ���� ũ��� �ּ� ���� ũ��� ���ų�, �ϳ� �� ũ��.
		// 2. �ִ� ���� �ִ� ���Ҵ� �ּ� ���� �ּ� ���Һ��� �۰ų� ����.
		//    �̶� �˰��� ���� �ʴٸ� �ִ� ��, �ּ� ���� ���� ���� ���� swap���ش�.
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