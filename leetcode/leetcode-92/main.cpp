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
     ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (left == right || !head || !head->next) return head;

         ListNode* l = nullptr, * ll = nullptr, * rr = nullptr;
         ListNode* node = head;
         int i = 1;
         for (; node; node = node->next, ++i) {
             if (i == left - 1) ll = node;
             else if (i == left) l = node;
             else if (i == right + 1) rr = node;
         }

         node = rr;
         for (; l != rr; l = l->next) {
             node = new ListNode(l->val, node);
         }

         if (left != 1) ll->next = node;
         else head = node;

         return head;
     }
 };

int main() {
	
    Solution s;
    
    ListNode* head = nullptr;
    //for (int i = 5; i >= 1; --i) {
    //    head = new ListNode(i, head);
    //}
    head = new ListNode(5, head);
    head = new ListNode(3, head);

    s.reverseBetween(head, 1, 2);

    //head = new ListNode(5, head);
    //head = new ListNode(3, head);

    //s.reverseBetween(head, 1, 1);

	return 0;
}