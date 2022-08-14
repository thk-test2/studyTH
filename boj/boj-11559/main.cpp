#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visited[12][6];
char arr[12][6];

int dirI[] = { -1, 1, 0, 0 };
int dirJ[] = { 0, 0, -1, 1 };

vector<pair<int, int>> bfs(int i, int j) {
	memset(visited, false, sizeof(visited));
	visited[i][j] = true;

	queue<pair<int, int>> q;
	q.push({ i, j });
	vector<pair<int, int>> v = { {i, j} };
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int ni = current.first + dirI[k], nj = current.second + dirJ[k];
			if (visited[ni][nj]) continue;
			if (ni >= 12 || ni < 0 || nj >= 6 || nj < 0) continue;
			if (arr[ni][nj] != arr[current.first][current.second]) continue;

			visited[ni][nj] = true;
			q.push({ ni, nj });
			v.push_back({ ni, nj });
		}
	}
	return v;
}

void move_puyos() {
	for (int i = 11; i >= 0; --i) {
		for (int j = 0; j < 6; ++j) {
			int cnt = 0;
			while (arr[i][j] == '.' && cnt <= i) {
				cnt++;
				for (int k = i; k > 0; --k) {
					arr[k][j] = arr[k - 1][j];
				}
				arr[0][j] = '.';
			}
		}
	}
}

void print_arr() {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int scan_arr() {
	int answer = 0;
	for (int k = 0; k < 18; ++k) {
		bool crashed = false;
		for (int i = 11; i >= 0; --i) {
			for (int j = 0; j < 6; ++j) {
				if (arr[i][j] == '.') continue;
				vector<pair<int, int>> v = bfs(i, j);
				if (v.size() >= 4) {
					crashed = true;
					//print_arr();
					for (auto& itr : v) {
						arr[itr.first][itr.second] = '.';
					}
				}
			}
		}
		move_puyos();
		if (crashed) answer++;
		else break;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> arr[i][j];
		}
	}
	cout << scan_arr();
	return 0;
}