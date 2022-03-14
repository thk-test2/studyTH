#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	unordered_map<string, int> m;
	int N;

	cin >> N;
	string name, cmd;
	for (register int i = 0; i < N; ++i) {
		cin >> name >> cmd;
		if (cmd == "enter") {
			m[name]++;
		}
		else {
			m[name]--;
		}
	}
	vector<string> v;
	for (auto& itr : m) {
		if (itr.second) {
			v.push_back(itr.first);
		}
	}
	sort(v.begin(), v.end(), greater<string>());
	for (auto& itr : v)
		cout << itr << "\n";

	return 0;
}