#include <iostream>
#include <map>

int main() {
    
    std::multimap<char, int> dial_map;

    dial_map.insert(std::make_pair('A', 2));
    dial_map.insert(std::make_pair('B', 2));
    dial_map.insert(std::make_pair('C', 2));

    dial_map.insert(std::make_pair('D', 3));
    dial_map.insert(std::make_pair('E', 3));
    dial_map.insert(std::make_pair('F', 3));

    dial_map.insert(std::make_pair('G', 4));
    dial_map.insert(std::make_pair('H', 4));
    dial_map.insert(std::make_pair('I', 4));

    dial_map.insert(std::make_pair('J', 5));
    dial_map.insert(std::make_pair('K', 5));
    dial_map.insert(std::make_pair('L', 5));

    dial_map.insert(std::make_pair('M', 6));
    dial_map.insert(std::make_pair('N', 6));
    dial_map.insert(std::make_pair('O', 6));

    dial_map.insert(std::make_pair('P', 7));
    dial_map.insert(std::make_pair('Q', 7));
    dial_map.insert(std::make_pair('R', 7));
    dial_map.insert(std::make_pair('S', 7));

    dial_map.insert(std::make_pair('T', 8));
    dial_map.insert(std::make_pair('U', 8));
    dial_map.insert(std::make_pair('V', 8));

    dial_map.insert(std::make_pair('W', 9));
    dial_map.insert(std::make_pair('X', 9));
    dial_map.insert(std::make_pair('Y', 9));
    dial_map.insert(std::make_pair('Z', 9));

    std::string dial;

    std::cin >> dial;

    int sum = 0;
    for (const auto & itr : dial) {
        sum += dial_map.find(itr)->second + 1; 
    }

    std::cout << sum << std::endl;
}