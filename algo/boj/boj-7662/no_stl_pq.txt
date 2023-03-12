#include <iostream>

using namespace std;

#define MAX (1000000 + 10000)

int T;

typedef struct st1
{
	int value;
	int deleteFlag;
}DATA;

DATA datas[MAX];
int dcnt;

typedef struct st2
{
	int value;
	int dataIdx;
}HEAP;

HEAP minHeap[MAX];
int minHn;

HEAP maxHeap[MAX];
int maxHn;

HEAP maxPop(HEAP * heap, int& hn)
{
	HEAP tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--].value = 0x80000000; /* -2147483648 */

	for (int i = 1; i * 2 <= hn;)
	{
		int child = heap[i * 2].value > heap[i * 2 + 1].value ? i * 2 : i * 2 + 1;
		if (heap[i].value > heap[child].value) break;
		swap(heap[i], heap[child]);
		i = child;
	}

	return ret;
}

void maxPush(HEAP * heap, int& hn, HEAP x)
{
	HEAP tmp;
	heap[++hn] = x;
	for (int i = hn; i > 1; i /= 2)
	{
		if (heap[i / 2].value > heap[i].value) break;
		swap(heap[i / 2], heap[i]);
	}
}

HEAP minPop(HEAP * heap, int& hn)
{
	HEAP tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--].value = 0x7fffffff; /* 2147483647 */

	for (int i = 1; i * 2 <= hn;)
	{
		int child = heap[i * 2].value < heap[i * 2 + 1].value ? i * 2 : i * 2 + 1;
		if (heap[i].value < heap[child].value) break;
		swap(heap[i], heap[child]);
		i = child;
	}

	return ret;
}

void minPush(HEAP * heap, int& hn, HEAP x)
{
	HEAP tmp;
	heap[++hn] = x;
	for (int i = hn; i > 1; i /= 2)
	{
		if (heap[i / 2].value < heap[i].value) break;
		swap(heap[i / 2], heap[i]);
	}
}

int main(void)
{
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++)
	{
		int k, dataCount;

		scanf("%d", &k);

		/* data, heap, 실제 존재하는 data 초기화 */
		dcnt = minHn = maxHn = dataCount = 0;

		for (int i = 0; i < k; i++)
		{
			char command;
			int value;

			scanf(" %c %d", &command, &value);

			if (command == 'I') /* 삽입 명령 */
			{
				datas[dcnt].value = value;
				datas[dcnt].deleteFlag = 0; /* tc가 여러 개이므로 초기화 */

				maxPush(maxHeap, maxHn, { value, dcnt });
				minPush(minHeap, minHn, { value, dcnt });

				dcnt++;
				dataCount++;
			}
			else /* 삭제 명령 */
			{
				if (dataCount == 0)
				{
					maxHn = minHn = 0;
					continue;
				}

				/* 우선순위가 높은 data가 삭제되었으면 불필요하므로 제거 */
				while (datas[maxHeap[1].dataIdx].deleteFlag) maxPop(maxHeap, maxHn);
				while (datas[minHeap[1].dataIdx].deleteFlag) minPop(minHeap, minHn);

				dataCount--;

				HEAP tmp;
				if (value == 1) /* 최댓값 삭제 */
				{
					tmp = maxPop(maxHeap, maxHn);
					datas[tmp.dataIdx].deleteFlag = 1;
				}
				else /* 최솟값 삭제 */
				{
					tmp = minPop(minHeap, minHn);
					datas[tmp.dataIdx].deleteFlag = 1;
				}
			}
		}

		if (dataCount)
		{
			/* 우선순위가 높은 data가 삭제되었으면 불필요하므로 제거 */
			while (datas[maxHeap[1].dataIdx].deleteFlag) maxPop(maxHeap, maxHn);
			while (datas[minHeap[1].dataIdx].deleteFlag) minPop(minHeap, minHn);

			HEAP maxValue = maxPop(maxHeap, maxHn);
			HEAP minValue = minPop(minHeap, minHn);

			printf("%d %d\n", maxValue.value, minValue.value);
		}
		else
			printf("EMPTY\n");
	}

	return 0;
}