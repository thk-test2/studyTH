#include <iostream>

using namespace std;

int N;

bool isPrime(int x) {
	if (x == 1) return false;
	for (int i = 2; i*i <= x; ++i) {
		if (x % i == 0)	return false;
	}
	return true;
}

void checknode(int currentNum, int cnt) {
	if (cnt == N) {
		cout << currentNum << "\n";
		return;
	}

	for (int j = 0; j < 10; j++) {
		int nextNum = currentNum * 10 + j;
		if (!isPrime(nextNum)) continue;
		checknode(nextNum, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[] = { 2, 3, 5, 7 };
	cin >> N;
	
	for (int i = 0; i < 4; ++i) {
		checknode(arr[i], 1);
	}
	return 0;
}