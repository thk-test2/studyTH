#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* itr = head;

        int size = 0;
        while (itr) {
            size++;
            itr = itr->next;
        }

        if (size == 1) {
            return nullptr;
        }
        else if (size == n) {
            head = head->next;
            return head;
        }

        itr = head;
        for (int i = 0; i <= (size - n); i++) {
            if (i == (size - n - 1))
                prev = itr;
            itr = itr->next;
        }

        prev->next = itr;
        return head;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}