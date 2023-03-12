#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;

		map<int, int> m;
		int N = nums.size();
		for (int i = 0; i < N; ++i) {
			if (i < k) {
				m[nums[i]]++;
				if (i == k - 1) ans.push_back(m.rbegin()->first);
			}
			else {
				m[nums[i - k]]--;
				m[nums[i]]++;
				while (m.rbegin()->second == 0) {
					m.erase(m.rbegin()->first);
				}
				ans.push_back(m.rbegin()->first);
			}
		}
		return ans;
	}
};

int main() {
	multiset<int> ms{ 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5 };
	ms.erase(2);

	map<int, int> m;
	m[1] = 4;
	m[2] = 5;
	cout << (*m.rbegin()).second;
	return 0;
}