#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* slowP = head;
        ListNode* fastP = head;

        bool hasCycle = false;
        while (fastP && fastP->next) {
            fastP = fastP->next->next;
            slowP = slowP->next;
            if (fastP == slowP) {
                hasCycle = true;
                break;
            }
        }
        return hasCycle;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}