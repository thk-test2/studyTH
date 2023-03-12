/* Time Over !! Need Optimization */

#include <iostream>
#include <map>
#include <unordered_map>

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
    for (const auto& kv : m)
        std::cout << kv.first << " " << kv.second << std::endl;
}

int main() {

    int count = 0;
    std::cin >> count;

    std::multimap<int, std::string> multi_map;
    int age;
    std::string name;

    for (int i = 0 ; i < count ; i++) {
        std::cin >> age >> name;

        multi_map.insert(std::make_pair(age, name));
    }
    print_map(multi_map);
}