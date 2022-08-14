#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, start, target;
	cin >> T;

	for (int test = 1; test <= T; test++) {
		cin >> N;
		int room[401] = { 0 };
		int Maximum = 0;
		for (int i = 0; i < N; i++) {
			cin >> start >> target;
			if (start > target) swap(start, target);

			if (target % 2 == 1)
				room[target + 1]++;
			if (start % 2 == 0)
				room[start - 1]++;
			for (int j = start; j <= target; j++) {
				room[j]++;
				Maximum = max(Maximum, room[j]);
			}
		}
		cout << "#" << test << " " << Maximum << "\n";
	}

	return 0;
}