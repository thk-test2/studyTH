#include <iostream>

using namespace std;

int vec[6] = { 5, 1, 7, 3, 5, -2 };
int dat[100];

int hashFunc(int x) {
	return x + 10;
}

void init() {
	for (int i = 0; i < 6; i++) {
		int idx = vec[i];
		int hash = hashFunc(idx);
		dat[hash] = 1;
	}
}

int main() {
	
	init();
	for (int q = 0; q < 10000; q++) {
		int t;
		cin >> t;
		int hash = hashFunc(t);
		dat[hash] == 1 ? cout << "O" : cout << "X";
		cout << "\n";
	}

	//const char* str = "ABBAAAE";

	//int buf[100] = { 0 };
	//for (int i = 0; str[i]; i++) {
	//	buf[str[i]]++;
	//}

	//for (int i = 0; i < 100; i++) {
	//	if (buf[i] == 0) continue;
	//	cout << i << ": " << buf[i] << "\n";
	//}

	return 0;
}