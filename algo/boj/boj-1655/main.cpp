#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v;
	int N, t;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		v.push_back(t);
		sort(v.begin(), v.end());
		if (v.size() % 2 == 0)
			cout << v[v.size() / 2 - 1] << "\n";
		else
			cout << v[v.size() / 2] << "\n";
	}

	return 0;
}