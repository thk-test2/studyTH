#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];
int N, K;

int bfs() {
	int answer = 987654321;
	visited[N] = true;
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		//visited[current.first] = true;
		if (current.first == K) {
			answer = min(answer, current.second);
			continue;
		}
		if (answer <= current.second) continue;

		if (current.first + 1 <= 100000 && !visited[current.first + 1]) {
			visited[current.first + 1] = true;
			q.push({ current.first + 1 , current.second + 1 });
		}
		if (current.first - 1 >= 0 && !visited[current.first - 1]) {
			visited[current.first - 1] = true;
			q.push({ current.first - 1 , current.second + 1 });
		}
		if (current.first * 2 <= 100000 && !visited[current.first*2]) {
			visited[current.first * 2] = true;
			q.push({ current.first*2 , current.second + 1 });
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	cout << bfs();

	return 0;
}