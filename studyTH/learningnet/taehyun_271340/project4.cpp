#include <iostream>
#include <string>

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
    void print() {
        cout << "name:" << name << ", addr:" << addr << ", age:" << age << endl;
    }
};

int main()
{
    // (3)번 과제에서 만든 People을 사용하세요.
    // 1. People을 힙에 10개 생성해 보세요..
    // People{"홍길동", "서울", 20} 으로 초기화 하세요..
    // 힌트) 메모리 할당과 생성자 호출을 분리 하세요
    People* people_ = static_cast<People*> (operator new(10 * sizeof(People)));
    for (int i=0 ; i < 10 ; ++i)
        new (&people_[i]) People{"홍길동", "서울", 20};

    // 2. 위에서 만드는 배열(버퍼)를 20개 키워 보세요..
    // A. 20개 버퍼를 새로 할당하고
    // B. 기존에 버퍼의 내용을 새로운 버퍼에 옮기세요.
    // move 생성자에 예외가 없다면 move 생성자로,
    // 예외가 있다면 복사 생성자로 옮기세요
    // C. 버퍼의 새로운 공간은 {"unknwon", "unknown", 0} 으로 초기화 하세요
    People* temp_people_ = static_cast<People*> (operator new( 20* sizeof(People)));
    for (int i=0; i < 20 ; ++i) {
        if (i < 10) {
            new (&temp_people_[i]) People(people_[i]);
        } 
        else
            new (&temp_people_[i]) People{"unknown", "unknown", 0};
    }

    // 3. 새로운 버퍼의 새용을 출력하세요.
    for (int i=0; i < 20 ; ++i) {
        temp_people_[i].print();
    }

    // 4. 버퍼을 줄이지는 말고 버퍼 끝에 있는 3개 객체를 파괴(명시적 소멸자 호출)해보세요.
    for (int i=17; i < 20 ; ++i) {
        temp_people_[i].~People();
    }
}