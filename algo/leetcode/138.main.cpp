/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
//         Node * new_head = head;
//         while (head) {
//             Node * temp = new Node(head->val);
//             temp->next = head->next;
//             temp->random = head->random;
            
//             head = head->next;
//         }
        
        Node* new_head = new Node(head->val);
        
        new_head->next = head->next;
        new_head->random = head->random;       
        
        return new_head;
    }
};
