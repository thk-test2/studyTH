
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int triangle(int part_sum, int i, int j) {

}

int main() {

    int height=0;
    std::cin >> height;
    std::cin >> std::ws;

    std::string line;
    std::vector<std::pair<int, int>> line_num;

    for (int i = 0; i< height ; i++) {
        getline(std::cin, line);
        std::stringstream ss(line);
        int token;
        
        while(ss >> token) {
            line_num.emplace_back(i, token);
        }
    }

    for( const auto & itr : line_num ) {
        std::cout << itr.first << " " << itr.second << std::endl;
    }
}