#include <iostream>

using namespace std;

template<typename ... Types> class MultiInterface : public Types... // public lambda1, public lambda2
{
public:
    MultiInterface(Types&&... args) : Types(args)... {} // lambda는 기본 생성자는 delete지만 복사 생성자는 가능

    // 기반 클래스의 특정함수를 사용할 수 있게..
    using Types::operator()...;
};

int main()
{
    MultiInterface f([](int a, int b) { return a + b;},              // class lambda1{}; lambda1();
                     [](int a, int b, int c) { return a + b + c; }); // class lambda2{}; lambda2();

    cout << f(1, 2) << endl;
    cout << f(1, 2, 3) << endl;
//    f(1, 2, 3, 4);

    return 0;
}
