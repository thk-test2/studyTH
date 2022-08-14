#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	unordered_map<string, int> m;
	string str, answer;
	int maximum = 0;

	for (int i = 0; i < N; ++i) {
		cin >> str;
		m[str]++;
		if (m.count(str) != 0) {
			int n = m[str];
			if (maximum <= n && answer <= str) {
				answer = str;
				maximum = n;
			}
		}
	}
	cout << answer << " " << maximum;
	return 0;
}