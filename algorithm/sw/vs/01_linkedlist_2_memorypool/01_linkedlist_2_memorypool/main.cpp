#include <iostream>
#include <ctime>

using namespace std;

struct Node {
    int x;
    Node* next;
};
//
//Node* head = nullptr;
//Node* last = nullptr;
//
//void addNode(int t) {
//    if (head == nullptr) {
//        head = new Node();
//        head->x = t;
//        head->next = nullptr;
//        last = head;
//        return;
//    }
//
//    last->next = new Node();
//    last->next->x = t;
//    last->next->next = nullptr;
//    last = last->next;
//}

Node Pool[10000000 * 2] = { 0 };
int pcnt = 0;
Node* Head = nullptr;
Node* Last = nullptr;

Node* myAlloc(int t, Node* next) {
    Pool[pcnt] = { t, next };
    return &Pool[pcnt++];
}

// 반드시 뒤에 추가해야 할 때
void addNode(int t) {
    if (Head == nullptr) {
        Head = myAlloc(t, nullptr); // &Pool[pcnt++];
        Last = Head;
        return;
    }
    Last->next = myAlloc(t, nullptr); // &Pool[pcnt++];
    Last = Last->next;
}

// 순서 상관없이 추가해도 될 때
void addNode_2(int t) {
    Head = myAlloc(t, Head);
}

int main() {
    int start = clock();
    for (int i = 0; i < 10; i++) {
        addNode_2(i);
    }
    int end = clock();

    cout << end - start << "\n";

    Node* p = Head;
    while (p != nullptr) {
        printf("%d ", p->x);
        p = p->next;
    }

    //Node* old;
    //while (head != nullptr) {
    //    old = head;
    //    head = head->next;
    //    delete old;
    //}

    return 0;
}
