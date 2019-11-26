#include <iostream>
#include <array>

int main() {

    int N, weight_limit;
    std::cin >> N >> weight_limit;

    std::pair<int, int> array[N];

    int weight, value;
    for (int i=0; i < N; ++i) {
        std::cin >> weight >> value;
        array[i] = std::make_pair(weight, value);
    }

    int weight_sum = 0; 
    int value_sum = 0;
    int biggest_value = 0;
    for (int i=0; i<N ; ++i) {
        weight_sum = 0; 
        value_sum = 0;
        if (weight_sum + array[i].first > weight_limit)
            continue;

        // if (value_sum + array[i].second > biggest_value) {
            weight_sum += array[i].first;
            value_sum += array[i].second;
        // }

        for (int j=i+1; j<N ; ++j) {
            if (weight_sum + array[j].first > weight_limit)
                continue;
            
            if (value_sum + array[j].second > biggest_value) {
                weight_sum += array[j].first;
                value_sum += array[j].second;  
            }
        }
        if ( value_sum > biggest_value )
            biggest_value = value_sum;
    }
    std::cout << biggest_value << std::endl; 
}