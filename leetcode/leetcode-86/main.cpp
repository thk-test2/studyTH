#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        int min_val = 101, max_val = -101, cnt = 0;
        for (ListNode* node = head; node; node = node->next) {
            min_val = min(min_val, node->val);
            max_val = max(max_val, node->val);
            cnt++;
        }
        if (min_val > x || max_val < x || cnt == 1) return head;

        ListNode* prev = head;
        ListNode* less_head = nullptr, * less_tail = nullptr;

        for (ListNode* node = head; node; node = node->next) {
            if (node->val >= x) {
                prev = node;
                continue;
            }
            if (node == head) head = node->next;
            else prev->next = node->next;

            if (less_head) {
                less_tail->next = node;
                less_tail = less_tail->next;
            }
            else {
                less_tail = node;
                less_head = less_tail;
            }
        }

        if (less_tail) {
            less_tail->next = head;
            return head = less_head;
        }
        else {
            return head;
        }
    }
};

int main() {
	
	return 0;
}