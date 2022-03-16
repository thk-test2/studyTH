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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=nullptr;
        ListNode* itr=head;
        
        int size=0;
        while(itr) {
            size++;
            itr=itr->next;
        }
        cout << size << endl;
        
        if (size == 1) {
            return nullptr;
        }
        else if (size == n) {
            head = head->next;
            return head;
        }
        
        itr = head;       
        for (int i=0; i<= (size-n) ; i++, itr = itr->next) {
            if (i == (size-n-1))
                prev = itr;
        }

        prev->next = itr;
        return head;
    }
};