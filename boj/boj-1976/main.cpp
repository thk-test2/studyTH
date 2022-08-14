#include <iostream>

using namespace std;

int parent[201];
int N, M;

int getParent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = getParent(parent[n]);
}

int setParent(int a, int b) {
	if (parent[a] == a) {
		return parent[a] = b;
	}
	return parent[a] = setParent(parent[a], b);
}

void unionParent(int a, int b) {
	int pa = getParent(a), pb = getParent(b);

	if (pa < pb) {
		setParent(b, pa);
	}
	else if (pb > pa) {
		setParent(a, pb);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}

	int n;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> n;
			if (n) {
				unionParent(i, j);
			}
		}
	}

	int prev_parent;
	cin >> n;
	prev_parent = getParent(n);
	for (int i = 2; i <= M; ++i) {
		cin >> n;
		if (prev_parent != getParent(n)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}