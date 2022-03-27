#include <iostream>

// 출처: https://ko.wikipedia.org/wiki/%EC%97%AC%EB%8D%9F_%ED%80%B8_%EB%AC%B8%EC%A0%9C

using namespace std;

int N, cnt;
// board[i]는 i번째 행에 퀸이 몇번째 열에 있는지 의미하는 변수이다. (행열은 서로 바뀌어도 된다.)
// 즉 board[0] = 3일때, (1,4) 혹은 (4,1) 위치에 퀸이 있다는 뜻이다.
int board[15];

void placeQueen(int y) {
	// y는 현재 몇개의 퀸이 배치되었는지를 의미하는 변수다.
	if (y == N) {
		// n개의 퀸이 배치가 되었다면 이 경우는 답이다.
		cnt++;
		return;
	}
	for (int j = 0; j < N; ++j) {
		// flag는 퀸이 배치될 수 있는지를 저장하는 플래그다.
		bool flag = true;
		for (int i = 0; i < y; ++i) {
			// 이미 배치가 끝난 퀸을 참고해서 j번째 칸에 퀸을 설치할 수 있는지를 확인한다.
			if (board[i] == j || abs(y - i) == abs(j - board[i])) {
				// i번째 줄에 있는 퀸과 같은 칸에 있거나, 대각선에 같은 곳에 있다면, j번째 칸에 대한 탐색을 중단한다.
				flag = false;
				break;
			}
		}
		if (flag) {
			// 여기까지 왔다면 y번째 줄에 j번째 칸에 퀸을 놔두는 것이 가능하다.
			// 어짜피 y 이전까지만 탐색하므로 제거하는 과정은 필요없다.
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