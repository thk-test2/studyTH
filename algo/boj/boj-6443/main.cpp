#include <iostream>
#include <cstring>

using namespace std;

char output[1001];
int alphabet[26];

void findana(int level, int strSize) {
	if (level == strSize) {
		cout << output << "\n";
		return;
	}
	for (int i = 0; i < 26; ++i) {
		if (alphabet[i] <= 0) continue;

		alphabet[i]--;
		output[level] = i + 'a';
		findana(level + 1, strSize);
		alphabet[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		
		int strSize = str.size();
		for (int i = 0; i < strSize; ++i) {
			alphabet[str[i] - 'a']++;
		}
		findana(0, strSize);
		memset(alphabet, 0, sizeof(alphabet));
	}
	return 0;
}