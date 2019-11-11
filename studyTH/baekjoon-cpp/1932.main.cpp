
#include <iostream>
#include <array>
#include <string>
#include <sstream>

// std::vector<std::pair<int, int>> num_vec;
std::array<std::array<int, 500>, 500> num_vec;
int height=0;
std::array<int, 500> result;

int triangle(int part_sum, int column, int row) {
    if (column == height)
        return part_sum;

    part_sum = part_sum + num_vec[column][row];
    std::cout << part_sum << std::endl;
    return std::max(triangle(part_sum, column+1, row), triangle(part_sum, column+1, row+1));
}

int main() {

    // int height=0;
    std::cin >> height;
    std::cin >> std::ws;

    std::string line;

    for (int i = 0; i< height ; i++) {
        getline(std::cin, line);
        std::stringstream ss(line);
        int token;
        int j=0; 
        while(ss >> token) {
            num_vec[i][j] = token;
            j++;
            // num_vec.emplace_back(i, token);
        }
    }

    // for( const auto & itr : num_vec ) {
    //     std::cout << itr.first << " " << itr.second << std::endl;
    // }

    int sum = triangle(0, 0, 0);
    std::cout << sum << std::endl;

    // int sum2 = 0;
    // int j=0;
    // for (int i = 0; i < height ; i++) {
    //     sum2 = sum2 + num_vec[i][j];
    //     std::max(sum2+num_vec[i+1][j], sum2+num_vec[i+1][j+1]);
    // }
}