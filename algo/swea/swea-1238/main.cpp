#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr auto MAX_SIZE = 101;

int visited[MAX_SIZE];
int N;

void init() {
	for (int i = 0; i < MAX_SIZE; ++i) {
		visited[i] = 0;
	}
}

int bfs(int start, vector<int> v[]) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	int max_cnt = 0;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		max_cnt = max(max_cnt, visited[current]);

		for (auto& itr : v[current]) {
			if (visited[itr] != 0) continue;
			visited[itr] = visited[current] + 1;
			q.push(itr);
		}
	}
	
	int answer = 0;
	for (int i = 0; i < MAX_SIZE; ++i) {
		if (visited[i] == max_cnt) {
			answer = max(answer, i);
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int start;
	for (int test = 1; test <= 10; ++test) {
		cin >> N >> start;

		int from, to;
		vector<int> v[MAX_SIZE];
		for (int i = 1; i <= N/2; ++i) {
			cin >> from >> to;
			v[from].push_back(to);
		}
		init();
		cout << "#" << test << " " << bfs(start, v) << "\n";
	}
	return 0;
}