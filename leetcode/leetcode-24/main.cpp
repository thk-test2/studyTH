#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = head, * cur = head->next;
        head = head->next;

        while (prev->next) {
            cur = prev->next;
            if (!cur) break;
            prev->next = cur->next;
            cur->next = prev;

            prev = prev->next;
            if (!cur->next || !prev) break;

            if (prev->next)
                cur->next->next = prev->next;
        }
        return head;
    }
};

int main() {
	
	return 0;
}