#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	long long N;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;

        long long sum = 1;
		long long temp = 1;
		bool checknum = false;
		while (sum < N) {
			if (!checknum) {
				temp *= 4;
			}
			sum += temp;
			checknum = !checknum;
		}
		checknum ? cout << "#" << test << " Alice\n"
			: cout << "#" << test << " Bob\n";
	}
	return 0;
}