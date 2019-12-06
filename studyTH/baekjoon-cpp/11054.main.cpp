#include <iostream>
#include <vector>

int main() {

    int N;
    std::cin >> N;

    std::vector<int> seq;

    for (int i=0; i < N; i++) {
        int A;

        std::cin >> A;
        seq.push_back(A);
    }

    std::vector<int> bitonic_seq;

    int back_back = 0;
    int back = 0; 

    bitonic_seq.push_back(back);
    for ( const auto& itr : seq ) {

        if ( back == itr )
            continue;
        else if ( back < itr ) {
            if ( back_back < itr ) {
                bitonic_seq.push_back(itr);
                back_back = back;
                back = itr;
            }
        }
        else if ( back > itr ) {
            if ( back_back > itr ) {
                bitonic_seq.push_back(itr);
                back_back = back;
                back = itr;
            }
        }
    }

    std::cout << bitonic_seq.size() << std::endl; 

    return 0;
}