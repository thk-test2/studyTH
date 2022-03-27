#include <iostream>
#include <vector>

using namespace std;

int arr[1000000];
int N;

int search(vector<int>& sub, int key) {
	int start = 0;
	int end = sub.size() - 1;
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (key > sub[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return end;
 }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	vector<int> sub;
	sub.push_back(arr[0]);
	for (int i = 1; i < N; ++i) {
		if (arr[i] > sub.back()) {
			sub.push_back(arr[i]);
		}
		else {
			sub[search(sub, arr[i])] = arr[i];
		}
	}
	cout << sub.size();
	return 0;
}