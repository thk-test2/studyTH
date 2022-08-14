#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;

    std::array<int, 1000> dp = {0,};
    std::array<int, 1000> dp_r = {0,};
    std::array<int, 1000> dp_total = {0,};
    std::vector<int> seq;

    for (int i=0; i < N; i++) {
        int A;

        std::cin >> A;
        seq.push_back(A);
    }
    for (int i = 0; i < N ; i++) {
        dp[i] = 1;
        for (int j=0; j <= i ; j++)
            if ( seq[j] < seq[i] && dp[i] < dp[j] +1)
                    dp[i]++;
    }
    // int biggest = *std::max_element(dp.begin(), dp.end());

    // std::cout << biggest << std::endl;

    for (int i = N-1; i > 0 ; i--) {
        if (dp_r[i] == 0)
            dp_r[i] = 1;
        for (int j= N-1; j > i; j--) {
            if ( seq[i] > seq[j] ) {
                if (dp_r[i] < dp_r[j] +1)
                    dp_r[i] = dp_r[j] +1;
            }
        }
    }
    // int biggest_r = *std::max_element(dp_r.begin(), dp_r.end());

    // std::cout << biggest_r << std::endl;

    for (int i = 0; i < N ; i++) {
        dp_total[i] = dp[i] + dp_r[i];
    }
    int biggest = *std::max_element(dp_total.begin(), dp_total.end()) - 1;
    std::cout << biggest << std::endl;

    return 0;
}