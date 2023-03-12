#include <iostream>

using namespace std;

class Data
{
public:
    Data()  {}
    ~Data() {}

    Data(const Data& t)
    {
        cout << "Copy" << endl;
    }
    Data(Data&& t) noexcept
    {
        cout << "Move" << endl;
    }
    Data& operator=(const Data& t)
    {
        cout << "Copy=" << endl;
        return *this;
    }
    Data& operator=(Data&& t) noexcept
    {
        cout << "Move=" << endl;
        return *this;
    }
};

// 방법 1. move setter와 copy setter를 별도의 함수로 제공
// 장점: 오버헤드가 없다.
// 단점: setter 함수를 2개를 제공해야 한다.

// 방법 2. call by value를 사용하는 방법
// 장점: setter 함수는 한 개만 제공하면 된다.
// 단점: 약가느이 오버헤드가 있다.(move 1회)

// 방법 3. forwarding reference를 사용하는 방법
// 장점: 오버헤드가 없고, 하나의 함수 템플릿만 제공하면 된다.
// 단점: side effect를 고려해야 한다.

class Test
{
    Data data;
public:
    // void setData(Data d) { data = d; }

    // 아래 코드는 무조건 Copy= 사용. d는 lvalue니까
    // void setData(const Data& d) { data = d; }

    // 1. 아래 코드는 무조건 Move=가 아니고 Copy=. 상수 객체는 move 될 수 없음
    //void setData(const Data& d) { data = move(d); }
    // rvalue 버전
    //void setData(Data&& d) { data = move(d); }

    // 2. call by value
    // void setData(Data d) { data = move(d); }

    // 3. forwarding reference
    template<typename T> void setData(T&& a)
    {
        // data = a; // copy
        // data = move(a); // move
        data = forward<T>(a);
    }
};

int main()
{
    Test test;

    Data d;
    test.setData(d);       // 실행 후에도 d를 사용가능
    test.setData(move(d)); // 실행 후에는 d를 사용불가

    AAA a;
    test.setData(a);
}
