#include <iostream>
#include <stack>

using namespace std;

using pos = pair<int, int>;

int map[101][101];
int answer;

void dfs(pair<int, int> start) {
	stack<pos> s;
	bool visited[101][101] = { false };
	visited[start.first][start.second] = true;

	s.push(start);
	while (!s.empty()) {
		pos temp = s.top();
		s.pop();
		int i = temp.first;
		int j = temp.second;

		if (i == 0) {
			answer = j;
			break;
		}

		if (j > 0 && map[i][j - 1] && !visited[i][j - 1]) {
			visited[i][j - 1] = true;
			s.push(make_pair(i, j - 1));
		}
		else if (j < 99 && map[i][j + 1] && !visited[i][j + 1]) {
			visited[i][j + 1] = true;
			s.push(make_pair(i, j + 1));
		}
		else if (i > 0 && !visited[i - 1][j]) {
			visited[i - 1][j] = true;
			s.push(make_pair(i - 1, j));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	int t;
	for (int test = 1; test <= 10; test++) {
		cin >> K;
		pos start;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> t;
				map[i][j] = t;
				if (t == 2) {
					start.first = i;
					start.second = j;
				}
			}
		}
		dfs(start);
		cout << "#" << test << " " << answer << "\n";
	}

	return 0;
}