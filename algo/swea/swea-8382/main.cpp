#include <iostream>
#include <queue>

using namespace std;

int x_1, y_1, x_2, y_2;
int minimum = 987654321;

struct Node {
	int x;
	int y;
	int level;
	int dir;
};

void bfs() {
	queue<Node> q;
	q.push({ x_1, y_1, 0, 1 });
	q.push({ x_1, y_1, 0, 2 });

	while (!q.empty()) {
		Node current = q.front();
		q.pop();
		int cx = current.x, cy = current.y, cl = current.level, cd = current.dir;
		if (cx == x_2 && cy == y_2) {
			minimum = min(minimum, current.level);
			continue;
		}
		
		if (cd == 1) {
			if (cy < y_2) {
				q.push({ cx, cy + 1, cl + 1, 3 - cd });
			}
			else {
				q.push({ cx, cy - 1, cl + 1, 3 - cd });
			}
		}
		else {
			if (cx < x_2) {
				q.push({ cx + 1, cy, cl + 1, 3 - cd });
			}
			else {
				q.push({ cx - 1, cy, cl + 1, 3 - cd });
			}
		}
	}
}

void init() {
	minimum = 987654321;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		init();
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		x_1 += 100, y_1 += 100, x_2 += 100, y_2 += 100;
		bfs();
		cout << "#" << test << " " << minimum << "\n";
	}
	return 0;
}