#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

using pos = pair<int, int>;

int arr[100][100];
bool visited[100][100];
bool success = false;

int dirI[] = { -1, 1, 0, 0 };
int dirJ[] = { 0, 0, -1, 1 };

pos start, target;

void travel() {
	queue<pos> q;
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		pos current = q.front();
		q.pop();
		if (current.first == target.first && current.second == target.second) {
			success = true;
			return;
		}
		for (int k = 0; k < 4; ++k) {
			int nI = current.first + dirI[k], nJ = current.second + dirJ[k];
			if (visited[nI][nJ]) continue;
			if (arr[nI][nJ] == 1 || nI < 0 || nI >= 100 || nJ < 0 || nJ >= 100) continue;
			visited[nI][nJ] = true;
			q.push({ nI, nJ });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T = 10;
	int N;
	string str;
	for (int test = 1; test <= T; ++test) {
		cin >> N; cin.ignore();
		for (int i = 0; i < 100; ++i) {
			getline(cin, str);
			int strSize = str.size();
			for (int j = 0; j < strSize; ++j) {
				arr[i][j] = str[j] - '0';
				if (arr[i][j] == 2) {
					start.first = i; start.second = j;
				}
				else if (arr[i][j] == 3) {
					target.first = i; target.second = j;
				}
			}
		}
		memset(visited, false, sizeof(visited));
		travel();
		cout << "#" << test << " " << success << "\n";
		success = false;
	}
	return 0;
}