Functor
===========
## 1. Functor란?

함수 객체라고 해석하는데, 이렇게 이해하기 보다는 **객체인데 함수**처럼 쓸수 있는거라고 이해하면 쉽다.

## 2. Functor 구현

별거 없다 class나 structure에 operator ()를 override 해주면 된다. 
> 구조체는 c++에서 class와 완전히 같다. 즉 상속 constructor 등등 모두 되는데 차이점은 class와는 다르게 access modifier를 지정해주지 않으면
멤버변수 함수 모두 public 으로 인식된다. 

```cpp
#include <iostream>
 
class myFunctorClass
{
    public:
        myFunctorClass (int x) : _x( x ) {}
        int operator() (int y) { return _x + y; }
    private:
        int _x;
};
 
int main()
{
    myFunctorClass addFive( 5 );
    std::cout << addFive( 6 ); // 객체 명addFive에 ()연산자를 붙여서 마치 함수처럼 객체를 사용함. 
 
    return 0;
}
```

## 3. Functor와 일반 함수와의 차이는?

함수 객체는 객체이기 때문에 멤버 변수를 사용할수 있다는 점. 일반 함수는 그럴수가 없다. 
> 만약 함수에 로컬 변수가 유지되게 하고 싶을때는 Closure라는 것을 쓴다. 다른 프로그래밍 언어들도 모두가지고 있는 개념


## 4. Functor의 종류?

STL의 많은 알고리즘이 함수 객체를 즐겨 쓰는데 아래와 같은 종류가 있다. 

1. Generator (발생자 ) : foo() 처럼 인자 없이 호출되는 함수 객체
2. Unary Function ( 단항 함수 ) : foo(x) 처럼 인자가 하나인 함수 객체
3. Binary Function ( 이항 함수 ) : 인자가 둘인 함수 객체
4. Predicate( 술어 ) : 인자의 개수와 관계없이 bool 값을 반환하는 함수 객체나 함수 포인터 ( 근데 Predicate는  STL에서 함수의 파라메터로 많이 넘기나 보다. 보통.. )
5. Unary Predicate ( 단항 술어 ) : bool 값을 반환하는 함수 객체나 포인터 인데 인자를 한개 받는경우
6. Binary Predicate  ( 이항 술어 ) :  위와 동일, 한데 인자를 두개 받는 경우.

## 5. Functor vs fucntion pointer

STL에 쓸때의 장단점을 써보면 아래와 같다. 

1. 함수 포인터 
단점 : STL에 쓰기위해 전역 함수로 만들 가능성이 높음 => 여러개면 네임스페이스가 어지러워진다함

2. 함수 객체 
장점 : 함수 포인터는 어떤 함수가 실행될지 컴파일 타임에 알수 없는데, 함수 객체는 컴파일 타임에 알수 있으므로 컴파일러의 inlining 후보로 선정 가


