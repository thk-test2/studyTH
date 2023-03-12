#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> um;
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (um.find(val) != um.end()) return false;

        nums.push_back(val);
        um[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (um.find(val) == um.end()) return false;

        // replace the element val in nums by last element of nums & delete last element
        int last = nums.back();
        um[last] = um[val];
        nums[um[val]] = last;

        nums.pop_back();
        um.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
	
	return 0;
}