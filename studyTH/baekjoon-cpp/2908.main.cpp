#include <iostream>

int main() {

    std::string num_1, num_2;

    std::cin >> num_1;
    std::cin >> num_2;

    char* cnum_1 = new char[num_1.size()];
    char* cnum_2 = new char[num_2.size()];

    int i = 0;
    for (auto r_itr = num_1.rbegin() ; r_itr != num_1.rend() ; r_itr++) {
        cnum_1[i] = *r_itr;
        i++;
    }
    int j = 0;
    for (auto r_itr = num_2.rbegin() ; r_itr != num_2.rend() ; r_itr++) {
        cnum_2[j] = *r_itr;
        j++;
    }

    // std::cout << cnum_1 << std::endl;

    int Num_1 = std::atoi(cnum_1);
    int Num_2 = std::atoi(cnum_2);

    if ( Num_1 > Num_2 )
        std::cout << Num_1 << std::endl;
    else
        std::cout << Num_2 << std::endl;

    delete [] cnum_1, cnum_2;
}