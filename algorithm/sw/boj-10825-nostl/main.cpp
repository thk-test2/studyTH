#include <iostream>

using namespace std;

struct HEAP {
    string name;
    int kr;
    int en;
    int math;
};

bool isMin(HEAP a, HEAP b) {
    if (a.kr == b.kr) {
        if (a.en == b.en) {
            if (a.math == b.math) {
                return a.name < b.name;
            } else {
                return a.math > b.math;
            }
        } else {
            return a.en < b.en;
        }
    } else {
        return a.kr > b.kr;
    }
}

void push (HEAP heap[], int& hn, HEAP x) {
    HEAP tmp;
    heap[++hn] = x;
    for (int i = hn; i>1; i/=2){
        if (isMin(heap[i/2], heap[i]))
            return;
        swap(heap[i/2], heap[i]);
    }
}

HEAP pop(HEAP heap[], int& hn) {
    HEAP ret, tmp;

    ret = heap[1];
    heap[1] = heap[hn--];

    for (int i = 1; i*2 <= hn;) {
        if (isMin(heap[i], heap[i*2]) && isMin(heap[i], heap[i*2+1]))
            break;
        else if (isMin(heap[i*2], heap[i*2+1])) {
            swap(heap[i*2], heap[i]);
            i = i*2;
        } else {
            swap(heap[i*2+1], heap[i]);
            i = i*2 + 1;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    HEAP heap[100100];
    int N, hn = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        HEAP x;
        cin >> x.name >> x.kr >> x.en >> x.math;
        push(heap, hn, x);
    }

    for (int i = 0; i < N; i++) {
        HEAP tmp = pop(heap, hn);
        cout << tmp.name << "\n";
    }

    return 0;
}
