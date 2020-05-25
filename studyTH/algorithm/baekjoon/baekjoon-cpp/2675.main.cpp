#include <iostream>

int main() {

    int T;
    std::cin >> T;

    int R;
    std::string s1;

    for (int i =0 ; i < T ; i++) {
        std::cin >> R;
        std::cin >> s1;

        for (auto c : s1)
            for (int j=0; j < R ; j++)
                std::cout << c;
        std::cout << std::endl;
    }

    return 0;
}