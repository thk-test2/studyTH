#include <iostream>

using namespace std;

constexpr auto MAXSIZE = 101;
int v[MAXSIZE];
int vSize;

int answer[MAXSIZE];
int aSize;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, A, B, n;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		vSize = 0, aSize = 0;
		cin >> N >> A >> B;
		for (int i = 0; i < N; ++i) {
			cin >> n;
			v[vSize++] = n;
		}

		int time = 0, mailCnt = 0, prevIdx = 0, curIdx = 0;
		int oldest = v[0];
		while (true) {
			time++;
			if (curIdx < vSize && time == v[curIdx]) {
				mailCnt++;
				curIdx++;
			}
			if (mailCnt >= A || time - oldest >= B) {
				mailCnt = mailCnt % 2 == 0 ? mailCnt / 2 : mailCnt / 2 + 1;
				for (int i = prevIdx; i < prevIdx + mailCnt; ++i) {
					answer[aSize++] = time;
				}
				prevIdx += mailCnt;
				if (prevIdx >= vSize) break;
				mailCnt = curIdx - prevIdx;
				oldest = v[prevIdx];
			}
		}
		cout << "#" << test << " ";
		for (int i = 0; i < aSize; ++i)
			cout << answer[i] << " ";
		cout << "\n";
	}

	return 0;
}