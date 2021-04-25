#include <iostream>

using namespace std;

//lvalue
// 등호(=)의 왼쪽과 오른쪽에 모두 놓일 수 있다.
// 이름(id)를 가진다.
// 단일 문장을 벗어나서 사용될 수 있다.
// 주소 연산자로 주소를 구할 수 있다.
// 참조를 리턴하는 함수

//rvalue
// 등호(=)의 오른쪽에만 놓일 수 있다.
// 이름(id)이 없다.
// 단일 문장에서만 사용된다.
// 주소 연산자로 주소를 구할 수 없다.
// 값을 리턴하는 함수. 임시객체. 정수/실수형 리터럴(literal)

int x = 10;
int f1() { return x; }
int& f2() { return x; }

int main()
{
    int v1 = 10, v2 = 10;

    v1 = 20; // v1: lvaue 20: rvalue
    20 = v1; // error
    v2 = v1;

    int* p1 = &v1;
    int* p2 = &10;

    f1() = 10;
    f2() = 20;

    const int c = 10;
    c = 20; // c는 rvalue? lvalue?
            // c는 수정 불가능한 lvalue
    // rvalue가 모두 상수인 것은 아니다.
    //Point().x = 10;      // ERROR
    //Point().set(10, 20); // OK
}
