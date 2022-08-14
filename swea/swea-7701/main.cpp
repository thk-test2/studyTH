#include <iostream>
#include <unordered_map>

using namespace std;

constexpr auto MAX = 20001;

string heap[MAX];
int hSize;

bool isMin(string a, string b) {
	if (a.size() < b.size()) return true;
	else if (a.size() == b.size()) {
		return a < b;
	}
	return false;
}

void push(string val) {
	heap[++hSize] = val;

	for (int i = hSize; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) return;
		swap(heap[i / 2], heap[i]);
	}
}

string pop() {
	if (hSize <= 0) return "";
	string result = heap[1];
	heap[1] = heap[hSize];
	heap[hSize--] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	for (int i = 1; i * 2 <= hSize; ) {
		int child = isMin(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (isMin(heap[i], heap[child])) break;
		swap(heap[i], heap[child]);
		i = child;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		hSize = 0;
		unordered_map<string, int> um;
		cin >> N;
		string str;
		for (int i = 0; i < N; ++i) {
			cin >> str;
			if (um.count(str) != 0) continue;
			um.insert({ str, 1 });
			push(str);
		}
		cout << "#" << test << "\n";
		while (hSize) {
			cout << pop() << "\n";
		}
	}
	return 0;
}