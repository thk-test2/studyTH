#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& blocks, int W) {
    int sum = 0, compare = 0;
    for (int i = 0; i < W; i++) {
        int left_max = 0, right_max = 0;

        left_max = *max_element(begin(blocks), begin(blocks) + i);
        right_max = *max_element(begin(blocks) + i, end(blocks));

        compare = min(left_max, right_max);
        if (blocks[i] <= compare)
            sum += compare - blocks[i];
    }
    return sum;
}

int main()
{
    vector<int> blocks;
    int n;
    int H, W;

    cin >> H >> W;

    for (int i = 0; i < W; i++) {
        cin >> n;
        blocks.push_back(n);
    }
    cout << solution(blocks, W);

    return 0;
}
