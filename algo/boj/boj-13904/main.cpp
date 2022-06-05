#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr auto SIZE = 1001;
bool visited[SIZE];

struct Node {
	int duedate;
	int point;
};

bool Compare(Node a, Node b) {
	if (a.point == b.point)
		return a.duedate < b.duedate;
	return a.point > b.point;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<Node> v;
	int N;
	cin >> N;
	int d, w;
	for (int i = 0; i < N; ++i) {
		cin >> d >> w;
		v.push_back({ d, w });
	}
	sort(v.begin(), v.end(), Compare);

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		int day = v[i].duedate;
		for (int j = day; j > 0; --j) {
			if (visited[j]) continue;
			visited[j] = true;
			sum += v[i].point;
			break;
		}
	}
	cout << sum << "\n";
	return 0;
}