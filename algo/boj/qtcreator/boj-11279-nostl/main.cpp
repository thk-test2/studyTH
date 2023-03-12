#include <iostream>

using namespace std;

#define MAX_SIZE 100100

bool comp(int a, int b) {
    return a > b;
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
    heap[count--] = -1;

    for (int i = 1; i*2 <= count;) {
        if (comp(heap[i], heap[i*2]) && comp(heap[i], heap[i*2+1]))
            break;
        else if (comp(heap[i*2], heap[i*2+1])) {
            swap(heap[i*2], heap[i]);
            i = i*2;
        } else {
            swap(heap[i*2+1], heap[i]);
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

    int heap[MAX_SIZE];
    int N, n, count = 0;
    cin >> N;

    for (int i = 0; i<N; i++) {
        cin >> n;
        if (n == 0) {
            int t = pop(heap, count);
            cout << t << "\n";
        }
        else
            push(heap, count, n);
    }

    return 0;
}
