#include <iostream>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 1, mod = 1000000007;

        for (int i = 2; i <= n; ++i) {
            ans = ans << (int)(log2(i) + 1);
            ans %= mod;

            ans += (i % mod);
        }
        return (int)ans;
    }
};

int main() {
	
	return 0;
}