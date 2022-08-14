#include <iostream>

using namespace std;

int dirI[] = { 0, 0, -1, 1 };
int dirJ[] = { -1, 1, 0, 0 };
double percent[4];
bool visited[30][30];
int N;

double travel(int level, int i, int j) {
	if (level == N) return 1.0;

	visited[i][j] = true;
	double result = 0.0;

	for (int k = 0; k < 4; ++k) {
		int ni = i + dirI[k], nj = j + dirJ[k];
		if (ni < 0 || ni >= 30 || nj < 0 || nj >= 30) continue;
		if (visited[ni][nj]) continue;
		result += percent[k] * travel(level + 1, ni, nj);
	}
	visited[i][j] = false;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 4; ++i) {
		int a; cin >> a;
		percent[i] = a / 100.0;
	}
	double R = travel(0, 14, 14);
	cout.precision(10);
	cout << fixed << R;
	return 0;
}