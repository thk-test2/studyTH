#include <iostream>
#include <string.h>

using namespace std;

class Cat
{
    char* name;
    int age;
public:
    Cat(const char* n, int a) : age(a) // shallow copy
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Cat() { delete[] name; }

    // 깊은 복사로 구현한 복사 생성자
    Cat(const Cat& c) : age(c.age)
    {
        name = new char[strlen(c.name) + 1];
        strcpy(name, c.name);
    }

    // 소유권 이전(자원전달)의 이동(move) 생성자
    Cat(Cat&& c) : age(c.age), name(c.name)
    {
        c.name = 0;  // 자원 release
    }
};

Cat foo() // 값 리턴: 임시객체(rvalue)
{
    Cat cat("NABI", 2);
    return cat;
}

int main()
{
//    Cat c1("NABI", 2);
//    Cat c2 = c1;  // runtime error

    Cat c = foo(); // 임시객체.
}
