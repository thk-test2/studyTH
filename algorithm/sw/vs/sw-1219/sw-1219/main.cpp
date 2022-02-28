#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int T, N;
bool exist = false;

void dfs(int A[][2], bool Visited[]) {
	stack<int> s;
	s.push(0);
	Visited[0] = true;

	while (!s.empty()) {
		int current = s.top();
		s.pop();
		if (current == 99) {
			exist = true;
			return;
		}
		for (int i = 0; i < 2; i++) {
			if (Visited[A[current][i]]) continue;
			Visited[A[current][i]] = true;
			s.push(A[current][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int test = 1; test <= 10; test++) {
		cin >> T >> N;
		int x, y;

		int A[100][2] = { 0 };
		bool Visited[100] = { true, };
		//memset(A, 0, sizeof(A));
		//fill(A[0], A[10], 0);

		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			//v.push_back({ x, y });
			A[x][0] == 0 ? A[x][0] = y : A[x][1] = y;
		}
		
		dfs(A, Visited);
		cout << "#" << test << " " << exist << "\n";
		exist = false;
	}

	return 0;
}