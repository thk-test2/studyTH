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
	ListNode* reverseList(ListNode* head) {
		ListNode* node = head;

		head = nullptr;
		for (; node; node = node->next) {
			//cout << node->val << "\n";
			head = new ListNode(node->val, head);
		}
		return head;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ListNode* head;
	ListNode N1(5);
	ListNode N2(4, &N1);
	ListNode N3(3, &N2);
	ListNode N4(2, &N3);
	ListNode N5(1, &N4);
	head = &N5;

	Solution s;
	ListNode* t = s.reverseList(head);

	for (; t; t = t->next) {
		cout << t->val << "\n";
	}
	return 0;
}