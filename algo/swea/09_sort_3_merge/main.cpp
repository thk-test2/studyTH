#include <iostream>

using namespace std;

constexpr auto SIZE = 10000;

int arr[SIZE];
int temp[SIZE];

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= end) temp[k++] = arr[j++];
    for (i = start; i <= end; ++i)
        arr[i] = temp[i - start];
}

void sort(int start, int end) {
    if (start == end) return;
    int mid = (start + end) / 2;
    sort(start, mid);
    sort(mid + 1, end);
    merge(start, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(0, N - 1);
    for (int i = 0; i < N; ++i)
        cout << arr[i] << "\n";
	return 0;
}