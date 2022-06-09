#include <iostream>
#include <vector>

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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        vector<ListNode*> v;
        ListNode* node = head;

        while (node) {
            v.push_back(node);
            node = node->next;
        }

        int n = v.size() - 1;
        for (int i = 0; i < n / 2 + 1; ++i) {
            v[i]->next = v[n - i];
            v[n - i]->next = v[i + 1];

            if (i == n - i || i + 1 == n - i)
                v[n - i]->next = nullptr;
        }
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}