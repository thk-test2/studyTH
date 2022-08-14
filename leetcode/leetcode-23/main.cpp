#include <iostream>
#include <vector>
#include <queue>

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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<int> pq;
		for (int i = 0; i < lists.size(); ++i) {
			ListNode* node = lists[i];
			for (; node; node = node->next) {
				pq.push(node->val);
			}
		}
		ListNode* head = nullptr;
		while (!pq.empty()) {
			head = new ListNode(pq.top(), head);
			pq.pop();
		}
		return head;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ListNode* temp = new ListNode(5);
	temp = new ListNode(4, temp);
	temp = new ListNode(1, temp);

	ListNode* temp2 = new ListNode(4);
	temp = new ListNode(3, temp);
	temp = new ListNode(1, temp);

	ListNode* temp3 = new ListNode(6);
	temp = new ListNode(2, temp);

	vector<ListNode*> lists;
	lists.push_back(temp);
	lists.push_back(temp2);
	lists.push_back(temp3);

	Solution s; s.mergeKLists(lists);

	return 0;
}