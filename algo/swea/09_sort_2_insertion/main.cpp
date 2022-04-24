#include <iostream>

using namespace std;

constexpr auto SIZE = 10000;

int arr[SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; ++i) {
        int target = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] > target) {
                arr[j + 1] = arr[j];
            }
        }
        arr[j + 1] = target;
    }
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << "\n";
    }
	return 0;
}