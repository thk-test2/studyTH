#include <iostream>

long factorial(unsigned N) {

    if (N == 0)
      return 1;

    return N*factorial(N-1);    
}

int main() {

    unsigned N = 0;

    std::cin >>  N;

    long ans = factorial(N);

    std::cout << ans << std::endl;

    return 0;
}