#include <iostream>

using namespace std;

class Test
{
public:
    Test()  { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
    Test(const Test& t) { cout << "Copy" << endl; }
    Test(Test&& t) noexcept { cout << "Move" << endl; }

    Test& operator=(const Test& t)
    {
        cout << "Copy=" << endl;
        return *this;
    }
    Test& operator=(Test&& t) noexcept
    {
        cout << "Move=" << endl;
        return *this;
    }
};

// lvalue를 전달하면 T: lvalue 참조 => const Test&
template<typename T>
typename remove_reference<T>::type &&
xmove(T&& obj)
{
    // const Test&& => Test(Test&&)로 보내려고 하니 ERROR
    //              => Test(const Test&) 복사 생성자로 보내는 것은 OK
    return static_cast<const Test&&>(obj);
//    return static_cast<typename remove_reference<T>::type &&>(obj);
}

int main()
{
    const Test t1;
    Test t2 = move(t1); // move ? copy ? error

//    Test t3 = static_cast<Test&&>(t1); // ERROR
}
