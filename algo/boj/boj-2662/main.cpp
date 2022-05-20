#include <iostream>
#include <vector>

using namespace std;

vector<int> info[301];
int memo[21][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		int cost, company;
		cin >> cost;
		for (int j = 1; j <= M; ++j) {
			cin >> company;
			info[i].push_back(company);
		}
	}

	return 0;
}