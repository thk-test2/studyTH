#include <iostream>

// ��ó: https://ko.wikipedia.org/wiki/%EC%97%AC%EB%8D%9F_%ED%80%B8_%EB%AC%B8%EC%A0%9C

using namespace std;

int N, cnt;
// board[i]�� i��° �࿡ ���� ���° ���� �ִ��� �ǹ��ϴ� �����̴�. (�࿭�� ���� �ٲ� �ȴ�.)
// �� board[0] = 3�϶�, (1,4) Ȥ�� (4,1) ��ġ�� ���� �ִٴ� ���̴�.
int board[15];

void placeQueen(int y) {
	// y�� ���� ��� ���� ��ġ�Ǿ������� �ǹ��ϴ� ������.
	if (y == N) {
		// n���� ���� ��ġ�� �Ǿ��ٸ� �� ���� ���̴�.
		cnt++;
		return;
	}
	for (int j = 0; j < N; ++j) {
		// flag�� ���� ��ġ�� �� �ִ����� �����ϴ� �÷��״�.
		bool flag = true;
		for (int i = 0; i < y; ++i) {
			// �̹� ��ġ�� ���� ���� �����ؼ� j��° ĭ�� ���� ��ġ�� �� �ִ����� Ȯ���Ѵ�.
			if (board[i] == j || abs(y - i) == abs(j - board[i])) {
				// i��° �ٿ� �ִ� ���� ���� ĭ�� �ְų�, �밢���� ���� ���� �ִٸ�, j��° ĭ�� ���� Ž���� �ߴ��Ѵ�.
				flag = false;
				break;
			}
		}
		if (flag) {
			// ������� �Դٸ� y��° �ٿ� j��° ĭ�� ���� ���δ� ���� �����ϴ�.
			// ��¥�� y ���������� Ž���ϹǷ� �����ϴ� ������ �ʿ����.
			board[y] = j;
			placeQueen(y + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cnt = 0;
	placeQueen(0);
	cout << cnt;
	return 0;
}