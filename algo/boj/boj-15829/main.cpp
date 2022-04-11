#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L;
	cin >> L;
	string str;
	cin >> str;
	unsigned long long hash = 0;
	for (int i = L-1; i > 0; --i) {
		unsigned long long temp = str[i] - 'a' + 1;
		hash = (hash + temp) * 31 % 1234567891;
	}
	hash += str[0] - 'a' + 1;
	cout << hash % 1234567891;
	return 0;
}