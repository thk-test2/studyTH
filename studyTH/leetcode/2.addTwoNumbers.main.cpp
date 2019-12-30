/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0;
        int n2 = 0;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        
        ListNode* t3 = nullptr;
        ListNode* ret = nullptr;
        int upper = 0;
        while ( t1 || t2 || upper) {
            
            n1 = t1 ? t1->val : 0;
            n2 = t2 ? t2->val : 0;
            int n3 = n1 + n2 + upper;
            if ( n3 >= 10 ){
                upper = 1;
            } else {
                upper = 0;
            }
            ListNode* temp = new ListNode(n3%10);
            
            if (!t3) {
                t3 = temp;
                ret = t3;
            }
            else {
                t3->next = temp;
                t3 = t3->next;
            }
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        
        return ret;
    }
};