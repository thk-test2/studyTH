#include <iostream>

using namespace std;
constexpr auto SIZE = 200001;

using ull = unsigned long long;

string strA;
string strB;
ull wei[SIZE];

bool check(int mid, int smallSize, bool aIsLong) {
	ull aHash = 0, bHash = 0;
	
	for (int i = 0; i < smallSize; ++i) {
		bHash = bHash * 31 + strB[i];
		if (i < mid - 1) continue;
		
		int longSize = aIsLong ? strA.size() : strB.size();
		for (int j = 0; j < longSize; ++j) {
			aHash = aHash * 31 + strA[j];
			if (j < mid - 1) continue;
			if (aHash == bHash) return true;
			if (aIsLong) {
				aHash = aHash - strA[j - mid + 1] * wei[mid - 1];
			}
			else {
				bHash = bHash - strB[j - mid + 1] * wei[mid - 1];
			}
		}
		if (aIsLong) {
			bHash = bHash - strB[i - mid + 1] * wei[mid - 1];
		}
		else {
			aHash = aHash - strA[i - mid + 1] * wei[mid - 1];
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> strA;
	cin >> strB;

	bool aIsLong = strA.size() > strB.size();
	int smallSize = aIsLong ? strB.size() : strA.size();
	wei[0] = 1;
	for (int i = 1; i <= smallSize; ++i) {
		wei[i] = wei[i - 1] * 31;
	}

	int start = 0, end = smallSize - 1;
	int mid = 0, answer = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (check(mid, smallSize, aIsLong)) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << answer << "\n";
	return 0;
}