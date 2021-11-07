#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string s;
    std::ifstream fin("../filestream/main.cpp");

    // fin >> s; // 파일의 첫번째 단어, #include

    std::vector<std::string> v;
    while( std::getline(fin, s) )
        v.push_back(s);

    for (auto& n : v)
        std::cout << n << std::endl;

    std::cout << s <<std::endl;
}
