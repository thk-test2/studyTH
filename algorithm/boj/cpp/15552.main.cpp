#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(nullptr);

	unsigned T;
	cin >> T;

	string s1, s2;

	while(T>0) {
		T--;

		cin >> s1 >> s2;
		unsigned n1 = stoi(s1);
		unsigned n2 = stoi(s2);

		cout << n1+n2 << '\n';
	}

	return 0;
}
