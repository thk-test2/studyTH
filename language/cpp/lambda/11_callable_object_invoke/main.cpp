#include <iostream>
#include <functional>

using namespace std;

// Function Object: () 왼쪽에 올 수 있는 type
// 모든 종류의 함수 포인터
// () 연산자를 재정의한 클래스
// Lambda Expression
// 함수와 함수를 가리키는 참조는 Function Object가 아니다.

// invoke: Callable object를 넣을 수 있다.
// std::function, std::bind, std::thread::thread에서 쓰일 수 있는 것들
// Function Object
// Pointer to member

void foo(int a, int b)
{

}

class Dialog
{
public:
    void Close() {}
    int color;
    void setColor(int c)
    {
        color = c;
        cout << color << endl;
    }
};

template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
//    return std::forward<F>(f)(std::forward<Types>(args)...);
//    return f(std::forward<Types>(args)...);
    return invoke(std::forward<F>(f),
                  std::forward<Types>(args)...);
}

int main()
{
    foo(1, 2);

    less<int> f;
    f(1, 2);

    [](int a, int b) { return a + b; }(1, 2);

    chronometry(less<int>(), 10, 20);

    Dialog dlg;
    chronometry(&Dialog::Close, &dlg);

//    void (Dialog::*f1)() = &Dialog::Close;
//    (dlg.*f1)();
//    f1(&dlg);
//    invoke(f1, &dlg);

    invoke(&foo, 10, 20); // foo(10, 20)
    invoke(&Dialog::setColor, &dlg, 2); // dlg.setColor(2);

    // 멤버 변수 포인터
    invoke(&Dialog::color, &dlg) = 20;
    cout << dlg.color << endl;

    return 0;
}
