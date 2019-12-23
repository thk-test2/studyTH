#include <string>
#include <iostream>

using namespace std;

class People
{
    string name;
    string addr;
    int age;
public:
    People(string n, string add, int a) : name(n), addr(add), age(a) {}

    // 복사 생성자, 대입연산자, Move 생성자, Move 대입연산자를 만드세요..
    // 실행 여부를 확인하기 위해 logging 해주세요
    People(const People& p) : name(p.name), addr(p.addr), age(p.age) {
        cout << "복사 생성자 호출!" << endl;
    }
    People& operator=(const People &p) {
        if (this == &p)
            return *this;
        this->name = p.name;
        this->addr = p.addr;
        this->age = p.age;
        cout << "대입 연산자 호출!" << endl;
        return *this;
    }

    People(People&& p) {
        this->name = p.name;
        this->addr = p.addr;
        this->age = p.age;
        cout << "Move 생성자 호출!" << endl;
    }

    People& operator=(People &&p) {
        if (this == &p)
            return *this;
        this->name = p.name;
        this->addr = p.addr;
        this->age = p.age;
        cout << "Move 대입 연산자 호출!" << endl;
        return *this;
    }
};

int main()
{
    People p1{ "홍길동", "서울", 20 };
    People p2 = p1;       // copy
    People p3 = move(p1); // move
}