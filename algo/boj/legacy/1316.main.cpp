#include <iostream>
#include <set>

int main() {

    int count = 0;
    std::cin >> count;
    std::string str[count];

    for (int i = 0 ; i< count ; i++) {
        std::cin >> str[i];
    }

    int no_group = 0;
    char prev = 0;
    std::set<char> cset;
    
    for (const auto & itr : str) {
        // std::cout << itr << std::endl;

        for (int i=0; i < itr.size() ; i++) {
            if (itr[i] != prev) {
                // 이전과 다르고 set에 있다면 group이 아니다
                if ( cset.find(itr[i]) != cset.end() ) {
                    // std::cout << i << " " << itr[i] << std::endl;
                    no_group++;
                    break;
                }
            }
            prev = itr[i];
            cset.insert(itr[i]);
        }
        // 다음 string을 위해 초기화
        prev = 0;
        cset.clear();
    }
    std::cout << count - no_group << std::endl;
}