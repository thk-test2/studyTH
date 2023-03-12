#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <unordered_map>

int main() {
    int count = 0;
    std::cin >> count;

    std::vector<int> int_vec;

    int temp = 0;
    for (int i = 0 ; i < count ; i++) {
        std::cin >> temp;
        int_vec.emplace_back(temp);
    }

    auto average = std::accumulate(int_vec.begin(), int_vec.end(), 0) / int_vec.size();

    std::cout << average << std::endl;

    std::sort(int_vec.begin(), int_vec.end());

    std::cout << int_vec[int_vec.size()/2] << std::endl;


    std::unordered_map<int, size_t> counts;
    for (int i : int_vec)
        ++counts[i];

    std::multimap<size_t, int, std::greater<size_t> > inv;
    for (auto p : counts)
        inv.insert(std::make_pair(p.second, p.first));

    auto e = inv.upper_bound(inv.begin()->first);

    auto sum = std::accumulate(inv.begin(),
        e,
        0,
        [](double a, std::pair<size_t, int> const &b) {return a + b.second; });

    std::cout << sum / std::distance(inv.begin(), e) << std::endl;


    std::cout << *std::max_element(int_vec.begin(), int_vec.end()) - *std::min_element(int_vec.begin(), int_vec.end()) << std::endl;
}