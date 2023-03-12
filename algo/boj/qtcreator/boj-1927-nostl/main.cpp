#include <iostream>
#include <climits>

using namespace std;

#define MAX_SIZE 100100

bool comp(int a, int b) {
    return a < b;
}

void push(int heap[], int& count, int n) {
    heap[++count] = n;
    for (int i = count; i > 1; i /= 2) {
        if (comp(heap[i/2], heap[i]))
            return;
        swap(heap[i/2], heap[i]);
    }
}

int pop(int heap[], int& count) {
    if (count == 0)
        return 0;

    int ret = heap[1];
    heap[1] = heap[count];
    heap[count--] = INT_MAX;

    for (int i = 1; i*2 <= count;) {
        if (comp(heap[i], heap[i*2]) && comp(heap[i], heap[i*2+1]))
            break;
        else if (comp(heap[i*2], heap[i*2+1])) {
            swap(heap[i], heap[i*2]);
            i = i*2;
        } else {
            swap(heap[i], heap[i*2+1]);
            i = i*2+1;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n, count = 0;
    int heap[MAX_SIZE];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        if (n) {
            push(heap, count, n);
        } else {
            cout << pop(heap, count) << "\n";
        }
    }

    return 0;
}
