#include <iostream>
#include <unordered_map>

using namespace std;
constexpr auto MAX = (1000000 + 10000);

int minHeap[MAX];
int minHn;

int maxHeap[MAX];
int maxHn;

int maxPop()
{
	int ret = maxHeap[1];
	maxHeap[1] = maxHeap[maxHn];
	maxHeap[maxHn--] = 0x80000000; /* -2147483648 */

	for (int i = 1; i * 2 <= maxHn;)
	{
		int child = maxHeap[i * 2] > maxHeap[i * 2 + 1] ? i * 2 : i * 2 + 1;
		if (maxHeap[i] > maxHeap[child]) break;
		swap(maxHeap[i], maxHeap[child]);
		i = child;
	}
	return ret;
}

void maxPush(int x)
{
	maxHeap[++maxHn] = x;
	for (int i = maxHn; i > 1; i /= 2)
	{
		if (maxHeap[i / 2] > maxHeap[i]) break;
		swap(maxHeap[i / 2], maxHeap[i]);
	}
}

int minPop()
{
	int ret = minHeap[1];
	minHeap[1] = minHeap[minHn];
	minHeap[minHn--] = 0x7fffffff; /* 2147483647 */

	for (int i = 1; i * 2 <= minHn;)
	{
		int child = minHeap[i * 2] < minHeap[i * 2 + 1] ? i * 2 : i * 2 + 1;
		if (minHeap[i] < minHeap[child]) break;
		swap(minHeap[i], minHeap[child]);
		i = child;
	}
	return ret;
}

void minPush(int x)
{
	minHeap[++minHn] = x;
	for (int i = minHn; i > 1; i /= 2)
	{
		if (minHeap[i / 2] < minHeap[i]) break;
		swap(minHeap[i / 2], minHeap[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	char cmd;
	int n;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		unordered_map<int, int> check;
		int k = 0;
		minHn = maxHn = 0;
		for (int i = 0; i < N; ++i) {
			cin >> cmd >> n;
			if (cmd == 'I') {
				maxPush(n);
				minPush(n);
				check[n]++;
				k++;
			}
			else {
				if (k == 0) continue;
				if (n == 1) {
					while (maxHn > 0 && check[maxHeap[1]] == 0) maxPop();
					check[maxHeap[1]]--;
				}
				else {
					while (minHn > 0 && check[minHeap[1]] == 0) minPop();
					check[minHeap[1]]--;
				}
				k--;
			}
		}
		if (k == 0) {
			cout << "EMPTY" << "\n";
		}
		else {
			while (maxHn > 0 && check[maxHeap[1]] == 0) maxPop();
			while (minHn > 0 && check[minHeap[1]] == 0) minPop();
			cout << maxHeap[1] << " " << minHeap[1] << "\n";
		}
	}
}