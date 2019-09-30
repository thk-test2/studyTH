#include <iostream>
#include <algorithm>

int main() {

    std::string str;
    std::cin >> str;

    const int number_alphabet = 26;

    std::transform(str.begin(), str.end(),str.begin(), ::toupper);

    // std::pair나 std::tuple을 써서 두 배열을 합치자.
    int number[number_alphabet] = {0,};
    char alpa[number_alphabet] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (auto c : str)
        number[c-65]++;

    int big_n = 0;
    int big_index = 0;
    for (int i = 0 ; i < number_alphabet ; i++) {
        if (number[i] > big_n) {
            big_n = number[i];
            big_index = i;
            // std::cout << big_n << " " << alpa[big_index] << std::endl;
        }
    }

    bool dupl = false;
    int count = -1;
    for (int i = 0 ; i < number_alphabet ; i++) {
        if (big_n == number[i])
            count++;
    }

    if(count != 0) {
        std::cout << '?' << std::endl;
    }
    else {
        std::cout << alpa[big_index] << std::endl;
    }

    return 0;
}