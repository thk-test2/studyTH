#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> plan;
bool Select[15] = { false };
int Maximum = 0;

void doSelect(int idx, bool sel) {
	for (int i = idx; i < idx + plan[idx].first; i++) {
		Select[i] = sel;
	}
}

void combi(int idx, int pay) {
	for (int i = idx; i < N; i++) {
		if (Select[i]) continue;

		if (i + plan[i].first > N) {
			Maximum = max(Maximum, pay);
			continue;
		}

		doSelect(i, true);
		if (i + plan[i].first == N) {
			Maximum = max(Maximum, pay + plan[i].second);
		}
		combi(i + plan[i].first, pay + plan[i].second);
		doSelect(i, false);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int T, P;
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		plan.push_back({ T, P });
	}
	combi(0, 0);
	cout << Maximum << '\n';

	return 0;
}