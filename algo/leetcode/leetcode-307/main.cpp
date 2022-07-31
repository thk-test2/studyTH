#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> m_tree;
    int N = 0;
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        m_tree.resize(N * 4);
        makeTree(1, 1, N, nums);
    }

    void update(int index, int val) {
        updateTree(1, 1, N, index + 1, val);
    }

    int sumRange(int left, int right) {
        return query(1, 1, N, left + 1, right + 1);
    }

    int makeTree(int idx, int start, int end, vector<int>& nums) {
        if (start == end) {
            return m_tree[idx] = nums[start - 1];
        }
        int mid = (start + end) / 2;
        int l = makeTree(idx * 2, start, mid, nums);
        int r = makeTree(idx * 2 + 1, mid + 1, end, nums);
        return m_tree[idx] = l + r;
    }

    void updateTree(int idx, int start, int end, int target, int val) {
        if (start == target && start == end) {
            // cout << val << "\n";
            m_tree[idx] = val;
            return;
        }
        else if (start > target || end < target) return;

        int mid = (start + end) / 2;
        updateTree(idx * 2, start, mid, target, val);
        updateTree(idx * 2 + 1, mid + 1, end, target, val);
        m_tree[idx] = m_tree[idx * 2] + m_tree[idx * 2 + 1];
    }

    int query(int idx, int start, int end, int left, int right) {
        if (start > right || end < left) return 0;
        if (start >= left && end <= right) return m_tree[idx];

        int mid = (start + end) / 2;
        int l = query(idx * 2, start, mid, left, right);
        int r = query(idx * 2 + 1, mid + 1, end, left, right);
        return l + r;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
	
	return 0;
}