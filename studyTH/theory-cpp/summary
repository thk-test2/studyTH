https://modoocode.com/135

1 - 2. 첫 C++ 프로그램 분석하기
- namespace에 이름을 지정하지 않으면, 해당 파일에서만 접근이 가능하고 static으로 동작한다.
- using namespace std; 는 권장하지 않는다. 너무 거대하고 버전별 차이가 많이 때문


2 - 2. C++은 C 친구일까
- 레퍼런스 & 로 변수를 받으면 하나의 별명이 된다.
- 레퍼런스는 정의시 반드시 초기화 되어야 한다. 컴파일시 원래 가리키던 변수의 주소값으로 치환된다.
- 상수에 대한 참조를 하려면 const 키워드를 사용한다.
- 레퍼런스의 배열은 불가, 배열의 레퍼런스는 가능
- 레퍼런스를 리턴하는 함수는 헷갈리는 부분이니 더 공부해보자. 우측값 관련됨


4 - 1. 이 세상은 객체로 이루어져 있다
- 클래스는 객체를 만들어내는 설계도 라고 할 수 있다.
- static 멤버는 유일하게 존재하며 객체 간에 공유된다.


4 - 3. 스타크래프트를 만들자 ① (복사 생성자, 소멸자)
- 복사 생성자를 오버로딩 하지 않으면 default 복사 생성자를 쓰는데,
  동적 할당 같은 경우 포인터만 복사가 되므로 얕은 복사가 된다.
- 이럴땐 오버로딩 하여 Deep copy가 되도록 정의해야 한다.


4 - 6. 클래스의 explicit와 mutable 키워드
- explicit는 컴파일러가 묵시적으로 생성자를 찾아 실행하는 것을 막는다.
- const method 내에서는 멤버 변수의 값을 바꾸는 것이 불가능 하지만,
  mutable 로 멤버 변수를 선언하였다면 const 메소드에서도 변경이 가능하다.
- getUserInfo()에서 cache를 업데이트 하는것을 생각해볼 수 있다.


5 - 2.
- 두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩 하는 것이 좋습니다.
  (예를 들어 Complex 의 operator+(const Complex&, const Complex&) 와 같이 말입니다.)

- 두 개의 객체 사이의 이항 연산자 이지만 한 객체만 값이 바뀐다던지 등의
  동등하지 않는 이항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다.
  (예를 들어서 operator+= 는 이항 연산자 이지만 operator+=(const Complex&) 가 낫다)

- 단항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다 (예를 들어 operator++ 의 경우 멤버 함수로 오버로딩 합니다)

- 일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야 합니다 (강좌 앞 부분 참고)


5 - 3. 연산자 오버로딩 프로젝트 - N 차원 배열
- static_cast : 우리가 흔히 생각하는, 언어적 차원에서 지원하는 일반적인 타입 변환
- const_cast : 객체의 상수성(const) 를 없애는 타입 변환. 쉽게 말해 const int 가 int 로 바뀐다.
- dynamic_cast : 파생 클래스 사이에서의 다운 캐스팅 (→ 정확한 의미는 나중에 다시 배울 것입니다)
- reinterpret_cast : 위험을 감수하고 하는 캐스팅으로 서로 관련이 없는 포인터들 사이의 캐스팅 등


6 - 1. C++ 표준 문자열 & 부모의 것을 물려쓰자 - 상속
- 만일 위처럼 public 형태로 상속 하였다면 기반 클래스의 접근 지시자들에 영향 없이 그대로 작동합니다.
- 즉 파생 클래스 입장에서 public 은 그대로 public 이고, protected 는 그대로 protected 이고, private 은 그대로 private 입니다.

- 만일 protected 로 상속하였다면 파생 클래스 입장에서 public 은 protected 로 바뀌고 나머지는 그대로 유지됩니다.

- 만일 private 으로 상속하였다면 파생 클래스 입장에서 모든 접근 지시자들이 private 가 됩니다.


6 - 2. 가상(virtual) 함수와 다형성
- dynamic_cast는 실행시간에 객체의 타입을 확인해서 메소드를 호출시킨다.
- virtual 키워드로 메소드를 정의하면 실행시간에 다형성에 따라 불리는 것이 달라진다.
- virtual 메소드를 overide 할때 자식 메소드에서  virtual 키워드를 안써도 되지만,
  헷갈릴 수 있으니 그냥 쓰자.


6 - 3. 가상함수와 상속에 관련한 잡다한 내용들
- 기반 클래스에서 파생 클래스의 함수에 접근할 때 항상 기반 클래스의 포인터를 통해서 접근하였습니다.
  하지만, 사실 기반 클래스의 레퍼런스여도 문제 없이 작동합니다.
- 가상 함수를 쓰면 vtable 관리 비용과 동적으로 타입을 결정해야하는 비용이 들어간다.
- 다중 상속시 상속 순서에 따라 생성자가 호출된다.
- 상속시 부모 생성자를 명시적으로 호출해야 된다는데.. 진짜? 아니다.
  기본 생성자를 호출함. 특정 생성자를 호출하고 싶으면 호출하면 됨.

- 다양한 기능을 하는 클래스의 디자인: 브리지 패턴, 중첩된 일반화, 다중 상속. 각 방법의 장단점이 있다.


7장. C++ 에서의 입출력

8장. Excel 만들기 프로젝트


9장. TMP 개념 이해

9 - 1. 코드를 찍어내는 틀 - C++ 템플릿(template)
- 클래스 템플릿에 인자를 전달해서 실제 코드를 생성하는 것을 클래스 템플릿 인스턴스화 (class template instantiation) 라고 합니다.

- 템플릿이 인스턴스화 되지 않고 덩그러니 있다면 컴파일 시에 아무런 코드로 변환되지 않습니다.
  템플릿은 반드시 인스턴스화 되어야지만 비로소 컴파일러가 실제 코드를 생성하게 되지요.

- 함수 템플릿은 인스턴스화를 안해도 컴파일러가 알아서 해석한다.

- 함수 객체(Function Object - Functor)의 도입
  - struct 형태로 단순히 operator()만 정의
  - 함수는 아니지만 함수 인 척을 하는 객체를 함수 객체 (Function Object), 혹은 줄여서 Functor 라고 부릅니다.
  - 그렇다면 뭐가 더 나은 방법일까요? Functor? 아니면 구닥다리 함수 포인터?
  - 일단, 클래스 자체에 여러가지 내부 state 를 저장해서 비교 자체가 복잡한 경우에도
    손쉽게 사용자가 원하는 방식으로 만들어낼 수 있습니다.
  - 뿐만 아니라, 함수포인터로 함수를 받아서 처리한다면 컴파일러가 최적화를 할 수 없지만,
    Functor 를 넘기게 된다면 컴파일러가 operator() 자체를 인라인화 시켜서 매우 빠르게 작업을 수행할 수 있습니다.

- std::array 활용 하기
  - 배열처럼 컴파일 시에 스택에 할당됨
  - 메소드 인자로 넘길 때 템플릿을 쓰면 편하다.


9 - 2. 가변 길이 템플릿 (Variadic template)
- C++ 17 이전의 가변 길이 템플릿은 재귀적 호출을 이용했다.
  템플릿은 컴파일 때 결정이 되므로, 종료 조건의 메소드를 템플릿 메소드 이전에 작성해야 한다.

- 파라미터팩에 sizeof... 연산자를 사용할 경우 전체 인자의 개수를 리턴한다.

- C++ 17에 소개된 Fold expression을 통해 좀더 깔끔하게 표현이 가능하다.


9 - 3. 템플릿 메타 프로그래밍 (Template Meta programming)
- 템플릿을 사용하면 객체를 생성하지 않더라도, 타입에 어떠한 값 을 부여할 수 있고,
  또 그타입들을 가지고 연산 을 할 수 있다는 점 입니다.
- 또한 타입은 반드시 컴파일 타임에 확정되어야 하므로, 컴파일 타임에 모든 연산이 끝나게 됩니다.
  이렇게 타입을 가지고 컴파일 타임에 생성되는 코드로 프로그래밍을 하는 것을 메타 프로그래밍(meta programming) 이라고 합니다.
- TMP 를 왜 쓰는가?
  - 사실은어떠한 C++ 코드도 템플릿 메타 프로그래밍 코드로 변환할 수 있다는 점입니다(물론 엄청나게 코드가 길어지겠지만요).
  - 게다가 템플릿 메타 프로그래밍으로 작성된 코드는 모두 컴파일 타임에 모든 연산이 끝나기 때문에
     프로그램 실행 속도를 향상 시킬 수 있다는 장점이 있습니다 (당연히도 컴파일 시간은 엄청 늘어나게 됩니다).
  - 단점: 코딩도 어렵고 디버깅도 어렵다

- C++11부터 typedeff 대신에 직관적인 using 키워드를 사용할 수 있다.
  - typedef Ratio_add<rat, rat2> rat3;
    using rat3 = Ratio_add<rat, rat2>;
  - typedef void (*func)(int, int);
    using func = void (*)(int, int);

- Ratio 예제: 마치 Ratio 클래스의 객체를 생성한 것 같지만, 실제로 생성된 객체는 한 개도 없고,
  단순히 타입들을 컴파일러가 만들어낸 것 뿐입니다.


10장. STL 활용법 익히기

10 - 1. C++ STL - 벡터(std::vector), 리스트(list), 데크(deque)
  1) C++ Standard Template Library
  - 임의 타입의 객체를 보관할 수 있는 컨테이너 (container)
  - 컨테이너에 보관된 원소에 접근할 수 있는 반복자 (iterator)
  - 반복자들을 가지고 일련의 작업을 수행하는 알고리즘 (algorithm)

  => 반복자를 이용해 컨테이너를 추상화 시켜서 접근할 수 있기 때문에
  N 개의 알고리즘 코드만으로 M 종류의 컨테이너들을 모두 지원할 수 있게됨

  2) std::vector
  - 컨테이너는 크게 두가지가 있다.
    - 시퀀스 컨테이너 : 배열처럼 객체들을 순차적으로 보관
    - associative container : 키를 바탕으로 대응되는 값을 찾아줌

  - vector 에는 원소들이 메모리 상에 순차적으로 저장되어 있어
    임의의 위치에 있는 원소를 접근하는 것을 매우 빠르게 수행할 수 있다.
  - 일반적인 복잡도 순서: O(1) < O(logn) < O(n) < O(nlogn) < O(n^2)

  - vector의 경우 임의의 위치에 있는 원소에 접근을 O(1) 로 수행함
  - 맨 뒤에 새로운 원소를 추가하거나 제거하는 것도 O(1) 로 수행함

  - 추가하는 작업을 amortized O(1) 이라고 하는데,
    vector에 할당된 공간을 다 썼을 때 할당을 새로 하고 복사가 일어나기 때문.
    이 때는 O(n).

    - 임의의 위치 원소 접근 ([], at) : O(1)

    - 맨 뒤에 원소 추가 및 제거 (push_back/pop_back) : amortized O(1); (평균적으로 O(1) 이지만 최악의 경우 O(n) )

    - 임의의 위치 원소 추가 및 제거 (insert, erase) : O(n)

  3) iterator
  - 컨테이너의 원소에 접근할 수 있는 포인터와 같은 객체
  - vector는 begin() 과 end() 로 얻는다.
    end()의 경우 마지막 원소 한칸 뒤를 가리킴.
    begin() == end() 가 빈 벡터를 표현할 수 있기 때문

  - 컨테이너에 원소를 추가하거나 제거하게 되면 기존에 사용하였던 모든 반복자들을 사용할 수 없게 된다.

  - const_iterator 는 값을 바꿀 수 없고 탐색만 가능. cbegin() 과 cend() 로 얻음
  - reverse iterator 는 거꾸로 접근함. rbegin() 과 rend()

  4) range based for loop
  - 코드를 직관적으로 나타낼 수 있다.
  for (int elem : vec) {
    std::cout << "원소 : " << elem << std::endl;
  }

  for (const auto& elem : vec) {
    std::cout << elem << std::endl;
  }

  5) std::list
  - 양방향 연결 구조를 가진 자료형.
  - vector와 달리 임의의 위치에 있는 원소에 바로 접근이 불가.
  - 하지만 임의의 위치에 원소를 추가할 때는 O(1). 링크만 바꿔주면 되기 때문이다.
  - vector 와 달리 원소를 지워도 반복자가 무효화되지 않는다.
    각 원소들의 주소값이 바뀌지 않기 때문.

  6) std::deque
  - 임의의 위치에 접근: O(1)
  - 맨 뒤에 원소를 추가: O(1)
  - 맨 앞에 원소를 추가: O(1)
  - 임의의 위치에 원소 추가: O(n)

  - 메모리 상에 연속적으로 있지 않다. 메모리를 더 써서 성능을 늘림

  7) 그래서 어떤 컨테이너를 사용해야돼?
  어떠한 컨테이너를 사용할지는 전적으로 이 컨테이너를 가지고 어떠한 작업들을 많이 하냐에 달려있습니다.

  - 일반적인 상황에서는 그냥 벡터를 사용한다 (거의 만능이다!)

  - 만약에 맨 끝이 아닌 중간에 원소들을 추가하거나 제거하는 일을 많이 하고,
    원소들을 순차적으로만 접근 한다면 리스트를 사용한다.

  - 만약에 맨 처음과 끝 모두에 원소들을 추가하는 작업을 많이하면 덱을 사용한다.


10 - 2. C++ STL - 셋(set), 맵(map), unordered_set, unordered_map
  - 특정 키가 연관 컨테이너에 존재하는지 유무 : set, multiset
  - 특정 키에 대응되는 값이 무엇인지 질의 : map, multimap

  1) std::set
  - insert() 를 써서 추가. '어디에' 추가하는지 정보가 없고, 데이터에 원소 존재 여부만이 중요한 정보임
  - set에 원소 추가/삭제 작업은 O(logN) => balanced binary search tree 로 구현됨
  - find() 메소드 제공. 중복된 원소를 허용하지 않음
  - 커스텀 객체를 set에 넣고 싶다면, operator< 를 오버로딩 해야함. 비교하여 추가/삭제 하기 때문
    아니면 객체 비교 functor 정의

  - 원소 삽입/삭제: O(logN), 탐색도 O(logN)

  2) std::map
  - set 과 거의 비슷하지만 키에 대응되는 value 까지 보관
  - std::make_pair : 인자로 들어오는 객체를 보고 타입을 추측하여 std::pair 객체를 만들어 리턴
  - operator[] 를 이용해 새 원소를 추가할 수도 있다.
  pitcher_list["니퍼트"] = 3.56;
  pitcher_list["박종훈"] = 3.76;
  pitcher_list["켈리"] = 3.90;

  - *itr 가 pair를 가리키게 되므로, itr->first가 key이며 itr->second 가 value 이다.
  - [] 연산자는 맵에 없는 키를 참조하게 되면 자동으로 값의 default 생성자를 호출해서 추가함
  - 따라서 find() 를 써서 찾는게 좋다.
  - map 역시 중복된 원소를 허락하지 않는다.

  3) multiset, multimap
  - 중복 원소를 허락한다.
  - multimap은 [] 연산자를 사용할 수 없다. 키가 중복될 수 있기 때문
  - equal_range 함수의 경우 인자로 멀티맵의 키를 받은 뒤에,
    이 키에 대응되는 원소들의 반복자들 중에서시작과 끝 바로 다음을 가리키는 반복자를 std::pair 객체로 만들어서 리턴합니다.
    즉, begin() 과 end() 를 std::pair 로 만들어서 세트로 리턴한다고 볼 수 있겠지요.

  4) unordered_set, unordered_map
  - 기존 set 이나 map 은 정렬되서 들어갔음
  - unordered 의 경우 insert, erase, find 모두 O(1) 로 수행됨.
  - 내부적으로 hash map으로 구현되어 있다. 해시 함수의 가장 중요한 성질은 같은 원소는 같은 해시값을 리턴한다는 점이다.
  - 삽입/탐색 최선: O(1), 최악: O(n) => 모든 원소가 해시 충돌이 일어났을 때

  - 할당 공간을 다 썼을 때는 rehash 가 일어나며 O(N) 의 시간이 걸림

  5) 내가 만든 클래스를 unordered_set / unordered_map의 원소로 넣고 싶을 때
  - 클래스를 위한 hash function 을 직접 만들어줘야 한다.
  - int, double, std::string 같은 것은 hash function 이 이미 만들어져 있다.
    이들을 활용해야 한다.

  6) 그렇다면 뭘 써야돼?
  - 데이터의 존재 유무 만 궁금할 경우 → set

  - 중복 데이터를 허락할 경우 → multiset (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

  - 데이터에 대응되는 데이터를 저장하고 싶은 경우 → map

  - 중복 키를 허락할 경우 → multimap (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

  - 속도가 매우매우 중요해서 최적화를 해야하는 경우 → unordered_set, unordered_map
    (insert, erase, find 모두 O(1)O(1). 최악의 경우엔 O(N)O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야 한다!)


10 - 3. C++ STL - 알고리즘(algorithm)
  - 컨테이너에 반복자들을 가지고 이런 저런 작업을 쉽게 수행할 수 있도록 도와주는 라이브러리
  - template <typename Iter, typename Pred>
    void do_something(Iter begin, Iter end, Pred pred)

  1) 정렬
  - sort : 일반적인 정렬 함수라 생각하시면 됩니다.

  - stable_sort : 정렬을 하되 원소들 간의 순서를 보존합니다.
    만약에 벡터에 [a, b] 순으로 있었는데, a 와 b 가 크기가 같다면 정렬을 [a,b] 혹은 [b,a] 로 할 수 있습니다.
    sort 의 경우 그 순서가 랜덤으로 정해집니다. 하지만 stable_sort 의 경우 그 순서를 반드시 보존합니다.
    즉 컨테이너 상에서 [a,b] 순으로 있엇다면 정렬 시에도 (크기가 같다면) [a,b] 순으로 나오게 됩니다. 이 때문에 sort 보다 좀 더 느립니다.

  - partial_sort : 배열의 일부분만 정렬합니다. 상위 10개만 정렬하는 등

  2) 원소 제거 (remove, remove_if)
  - vec.erase(vec.begin() + 3); => v[3] 원소 하나 제거
  - vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
    => 값이 3인 모든 원소 제거
  - remove는 사실 해당 원소들을 뒤로 몰아주는 역할을 하고, erase가 삭제함

  3) lambda function
  - 쉽게 익명의 functor를 만들 수 있다. 알고리즘의 Pred에 유용하다
  - [capture list] (받는 인자) -> 리턴 타입 { 함수 본체 }
  - 사용법
    - [](int i) { return i % 2 == 1; }

    - [](int i) { return i % 2 == 1; }(3);  // true

    - auto func = [](int i) { return i % 2 == 1; };
      func(4);  // false;

  - capture list
    - &를 붙이면 레퍼런스로 캡쳐하여 값 변경 가능
    - 클래스의 멤버함수에서 람다를 사용할 때 멤버 변수를 참조하려면 this를 캡쳐

    - [] : 아무것도 캡쳐 안함

    - [&a, b] : a 는 레퍼런스로 캡쳐하고 b 는 (변경 불가능한) 복사본으로 캡쳐

    - [&] : 외부의 모든 변수들을 레퍼런스로 캡쳐

    - [=] : 외부의 모든 변수들을 복사본으로 캡쳐

  4) 원소 수정하기 (transform)
  - 벡터의 모든 원소에 1씩 더하기 등의 작업
  - std::transform(vec.begin(), vec.end(), vec2.begin(),
                   [](int i) { return i + 1; });

  5) 원소 탐색 (find, find_if, any_of, all_of 등)
  - 컨테이너에 find가 정의되어 있으면 그게 더 빠를 것이다.
  - current = std::find_if(current, vec.end(), [](int i) { return i % 3 == 2; });


10 - 4. C++ 문자열의 모든 것 (string 과 string_view)


11. C++ 에서 예외 처리
  1) throw semantic 으로 예외가 발생한 것을 명시적으로 나타낼 수 있다.
  - throw std::out_of_range("vector 의 index 가 범위를 초과하였습니다.");
  - std 에는 다양한 예외들이 정의되어 있다.

  - 중요한 점은 예외를 처리하는 부분에 도달하기까지 함수를 빠져나가면서
    stack에 생성된 객체들을 빠짐없이 소멸시킴(stack unwinding)

  2) 예외 처리
  -  try {
       data = vec.at(index);
     } catch (std::out_of_range& e) {
       std::cout << "예외 발생 ! " << e.what() << std::endl;
     }

  3) 여러 종류의 예외 받기
  try {
    func(c);
  } catch (char x) {
    std::cout << "Char : " << x << std::endl;
  } catch (int x) {
    std::cout << "Int : " << x << std::endl;
  } catch (std::string& s) {
    std::cout << "String : " << s << std::endl;
  } catch (const char* s) {
    std::cout << "String Literal : " << s << std::endl;
  }

  - Parent class와 Child class의 순서만 주의하자. Child를 앞에 두어야 제대로 캐치 가능(변환이 가능하므로)

  4) 모든 예외 받기
  try {
    func(c);
  } catch (int e) {
    std::cout << "Catch int : " << e << std::endl;
  } catch (...) {
    std::cout << "Default Catch!" << std::endl;
  }

  5) noexcept - 예외를 발생시키지 않는 함수
  - 예외가 발생할 수도 있지만, 컴파일러는 아닐 것이라고 믿게됨
  - 컴파일의 최적화 등에 쓰임
  - C++ 11부터 소멸자는 기본적으로 noexcept 이므로 소멸자에서 예외를 던지면 안 된다.


12장. rvalue와 move semantic 확실히 하고 넘어갈것

12 - 1. rvalue 레퍼런스와 이동 생성자
  1) 복사 생략
  - C++ 컴파일러는 복사를 생략할 때가 있다.
    불필요한 복사는 지양해야 하며 rvalue를 이용해 이동을 구현해 줄 때가 있다.

  2) lvalue와 rvalue
  - 모든 C++ expression은 크게 두 가지 카테고리로 구분된다.
  - lvalue는 주소값을 취할 수 있는 값으로 주로 좌측에 위치.
    정빈이의 정의로는 사용자가 정의한 변수라고 한다.
  - rvalue는 주소값을 가져올 수 없는 임시값.
    정빈's 정의는 사용자가 정의하지 않았는데 컴파일러가 연산과정중 생성하는 변수(메모리)

  - & 연산자 한번만 쓰면 lvalue의 레퍼런스를 얻을 수 있다.
  - MyString str3 = str1 + str2;
  => MyString str3(str1.operator+(str2));
  => MyString MyString::operator+(const MyString &s) 가 어떻게 MyString(const MyString &str); 를 호출할 수 있을까?
  => & 가 lvalue reference를 의미하지만 예외적으로 const T& 의 타입에 한해서 rvalue도 reference로 받을 수 있다.

  3) 이동은 어떻게?
  - 기존 복사 생성자에서는 const MyString & 로 받았기 때문에 string_content의 값의 변경이 불가능
  - rvalue만 받을 수 있는 방법이 있어야 함

  4) rvalue reference
  - &를 두 개 사용해서 정의

  5) 이동 생성자 작성 시 주의할 점
  - MyString을 C++ 컨테이너 들, vector 에 넣기 위해서는 이동 생성자에 noexcept 키워드를 써야함
  - 이동하다가 예외 발생시 메모리 해제하면 안되기 때문.
  - vector의 경우 이동 생성자가 noexcept 가 아닌 이상 이동 생성자를 사용하지 않는다.


12 - 2. Move 문법 (std::move semantics) 과 완벽한 전달 (perfect forwarding)
  1) move semantics
  - 좌측값도 복사가 아닌 이동을 시키고 싶다면?
  - swap 할 때 std::move() 로 lvalue를 rvalue로 캐스팅 시키고, 대입 연산자를 &&을 받도록 재정의

  2) Perfect forwarding와 Universal Reference
  - wrapper 함수를 생각해보자. vector의 emplace_back 함수는 인자를 받으면 알아서 객체를 생성해서 추가시킴
  - 템플릿 인자 T에 대해서 우측값 레퍼런스를 받는 형태를 Universal reference라고 한다.
  - 이는 rvalue만 받는 레퍼런스와 다르다.
    rvalue 뿐만 아니라 lvalue도 받으며, reference collapsing rule에 따라 T의 타입을 추론함
  - typedef int& T;
    T& r1;   // int& &; r1 은 int&
    T&& r2;  // int & &&;  r2 는 int&

    typedef int&& U U& r3;  // int && &; r3 는 int&
    U&& r4;                 // int && &&; r4 는 int&&
  - 즉 쉽게 생각하면 & 는 1 이고 && 은 0 이라 둔 뒤에, OR 연산을 한다고 보면 됩니다.
  - forward 함수는 u가 우측값 레퍼런스 일 때만 move를 적용한 것처럼 동작


13 - 1. 객체의 유일한 소유권 - unique_ptr
  1) 자원 관리의 중요성
  - C++에서 한번 획득한 자원은 직접 해제해주지 않는 이상 남아있음
    예외 발생 등 다양한 이유로 메모리가 남아있게 됨
  - RAII: Resource Acquisition Is Initialization
    자원 관리를 스택에 할당한 객체를 통해 수행하는 것이다.
  - 예외가 발생해서 함수를 빠져나가더라도, 스택에 정의되어 있는 모든 객체들은 빠짐없이 소멸자가 호출

  2) unique_ptr : 객체의 유일한 소유권
  - 메모리 관리의 두가지 문제점: leak과 double free
  - 특정 객체에 유일한 소유권을 부여하는 포인터 객체를 unique_ptr 이라고 한다.
  - -> 연산자를 오버로드 해서 포인터와 동일하게 사용 가능

  3) = delete 키워드
  - C++ 11에 추가된 기능으로 메소드 삭제. 명시적으로 쓰지 말라는 뜻
  - unique_ptr의 복사 생성자는 삭제되어 복사할 수 없음
  - move semantic으로 소유권 이전은 가능하다. 이동 생성자는 있음

  4) unique_ptr을 함수에 레퍼런스로 전달은 가능하나, 취지에 맞지 않다.
  - ptr.get()을 써서 임시 접근

  5) std::make_unique 를 써서 편하게 생성하자. 템플릿 인자로 전달된 클래스의 생성자들에게 perfect forwarding 수행
    std::unique_ptr<Foo> ptr(new Foo(3, 5));
    auto ptr = std::make_unique<Foo>(3, 5);

  6) vector 컨테이너에 넣으려면 move를 쓰거나, emplace_back 이용하면 직접 생성하면서 넣을 수 있음.
     emplace_back이 직접 perfect forwarding 수행

    - std::vector<std::unique_ptr<A>> vec;
      std::unique_ptr<A> pa(new A(1));

      vec.push_back(std::move(pa));  // 잘 실행됨

    - std::vector<std::unique_ptr<A>> vec;

      // vec.push_back(std::unique_ptr<A>(new A(1))); 과 동일
      vec.emplace_back(new A(1));


13 - 2. 자원을 공유할 때 - shared_ptr 와 weak_ptr
  1) shared_ptr 로 객체를 가리킬 경우 다른 shared_ptr 역시 그 객체를 가리킬 수 있다.
  - 몇 개의 shared_ptr 들이 원래 객체를 가리키는지 알아야한다.
    이를 reference count 라고 하며, 0가 되어야 객체를 해제할 수 있음
  - shared_ptr 끼리 공유하는 control block에 ref count를 기록함
  - make_shared를 통해 동적할당 횟수를 줄이자.
    => std::shared_ptr<A> p1(new A());
	=> std::shared_ptr<A> p1 = std::make_shared<A>();

  2) shared_ptr 은 인자로 주소값이 전달되면, 자기가 해당 객체를 첫번째로 소유하는 것처럼 행동함
  - A* a = new A();
    std::shared_ptr<A> pa1(a);
    std::shared_ptr<A> pa2(a);
  - 위의 경우 제어블록이 따로 생성됨.
    this를 사용해 shared_ptr을 만들고 싶으면 enable_shared_from_this를 상속

  3) weak_ptr
  - 순환 참조 문제 해결을 위해 등장. 스마트 포인터처럼 객체를 안전하게 참조하지만, 참조 개수를 늘리지는 않음
  - weak_ptr 자체로는 원래 객체를 참조할 수 없고, 반드시 shared_ptr로 변환해서 사용
  - 가리키고 있는 객체가 이미 소멸되었다면 empty shared_ptr로 변환되고,
    아닐경우 해당 객체를 가리키는 shared_ptr 로 변환된다.

  - shared_ptr의 제어블록에는 weak count도 존재한다.
  - shared_ptr은 0개 지만 아직 weak_ptr이 남아있을 때, 물론 객체는 해제되어 있는 상태이지만
    제어블록마저 해제해 버리면 제어 블록에서 참조 카운트가 0이라는 사실을 알 수 없다.


13장 연습문제
  - 가계도 관리 라이브러리


14. 함수를 객체로! (C++ std::function, std::mem_fn, std::bind)
  1) Callable : ()를 붙여서 호출 할 수 있는 모든 것
  - struct S {
      void operator()(int a, int b) { std::cout << "a + b = " << a + b << std::endl; }
    };
  - auto f = [](int a, int b) { std::cout << "a + b = " << a + b << std::endl; };
    f(3, 5);

  2) std::function
  - Callable 들을 객체의 형태로 보관할 수 있는 std::function 클래스 제공
  - std::function<void()> f3 = []() { std::cout << "Func3 호출! " << std::endl; };

  3) 멤버 함수를 std::function 으로 받으려면
  - 멤버 함수들은 구현상 자신을 호출한 객체를 암묵적 인자로 받고 있다.
  - std::function<int()> f1 = a.some_func;
    => std::function<int(A&)> f1 = &A::some_func;
  - 멤버 함수들의 경우 암시적 변환이 발생하지 않으므로 & 연산자를 통해 명시적으로 주소값을 전달해줘야 합니다.

  - mem_fn()을 쓰면 편리하게 전달할 수 있다.
    하지만 <functional> 헤더를 추가해야 하므로 람다 함수를 쓰는 경우가 많음.

  4) std::bind
  - 함수 객체 생성시에 인자를 특정한 것으로 지정할 수 있음
  - std::bind(add, 2, std::placeholders::_1);

  - 레퍼런스를 인자로 전달할 때 복사를 방지하기 위해 std::ref 사용함.
    // s1 이 그대로 전달된 것이 아니라 s1 의 복사본이 전달됨!
    auto do_something_with_s1 = std::bind(do_something, s1, std::placeholders::_1);
  =>
    auto do_something_with_s1 =
      std::bind(do_something, std::ref(s1), std::placeholders::_1);


15장. Thread : 매우 중요하고 프로젝트도 진행할 것

15 - 1. 동시에 실행을 시킨다고? - C++ 쓰레드(thread)
  1) 병렬 처리 했을 때 효율적인 로직을 thread를 생성하여 수행함
  - 같은 프로세스 내의 thread는 메모리를 공유한다.

  2) 사용법
  - <thread> 포함하여 사용함
  - thread t1(func1);
    thread t2(func2);
    thread t3(func3);
  - join() 이나 detach()를 안 쓰면 메인 프로그램 종료시 비정상 종료가 일어남

  3) thread 로 인자 전달
  - thread 생성자의 첫번째 인자로 함수 (정확히는 Callable 은 다 됩니다) 를 전달하고,
    이어서 해당 함수에 전달할 인자들을 쭈르륵 써주면 됩니다.
  - thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500,
       &partial_sums[i])
  - 출력시 cout 으로는 보장이 되지 않으므로 printf를 씀

  4) 생각 해보기
  - 문제 1
    피보나치 수열을 멀티 쓰레딩을 활용해서 빠르게 계산할 수 있는 방법은 없을까요?


15 - 2. C++ 뮤텍스(mutex) 와 조건 변수(condition variable)
  1) Race Condition
  - thread 끼리 메모리를 공유하기 때문에 비정상 결과 가능
  - 어셈블리 수준으로 가면 여러 줄이 수행되기 때문

  2) mutex
  - 한번에 하나의 쓰레드만 접근할 수 있도록 함
  - 한 쓰레드만 실행될 수 있는 부분을 critical section 이라 한다.
  - deadlock의 위험을 스마트 포인터를 써서 어느정도 회피한다.
    std::lock_guard<std::mutex> lock(m);

  - unique_ptr을 써도 모든 deadlock을 회피할 수 없다.
    따라서 check가 필요함
      if (!m1.try_lock()) {
        m2.unlock();
        continue;
      }

  3) deadlock 회피 가이드 라인
  - 중첩된 Lock 을 사용하는 것을 피해라
  - Lock 을 소유하고 있을 때 유저 코드를 호출하는 것을 피해라
  - Lock 들을 언제나 정해진 순서로 획득해라

  4) 생산자(Producer) 와 소비자(Consumer) 패턴
  - 생산자는 일감을 가져오고 소비자는 일을 수행한다.
  - 생산자가 work queue에 일을 넣을때 소비자는 loop 돌면서 체크하는 것이 아니라
    필요할 때 일어나면 된다.
  - 이 때 condition_variable 을 쓴다.
  - Consumer
    std::unique_lock<std::mutex> lk(*m);
    cv->wait(lk,
         [&] { return !downloaded_pages->empty() || *num_processed == 25; });

  - Producer
    // consumer 에게 content 가 준비되었음을 알린다.
    cv->notify_one();

  5) 뭘 배웠지?
  - 여러 쓰레드에서 같은 객체의 값을 수정한다면 Race Condition 이 발생합니다.
    이를 해결하기 위해서는 여러가지 방법이 있지만, 한 가지 방법으로 뮤텍스를 사용하는 방법이 있습니다.

  - 뮤텍스는 한 번에 한 쓰레드에서만 획득할 수 있습니다. 획득한 뮤텍스는 반드시 반환해야 합니다.

  - lock_guard 나 unique_lock 등을 이용하면 뮤텍스의 획득-반환을 손쉽게 처리할 수 있습니다.

  - 뮤텍스를 사용할 때 데드락이 발생하지 않도록 주의해야 합니다. 데드락을 디버깅하는 것은 매우 어렵습니다.

  - condition_variable 을 사용하면 생산자-소비자 패턴을 쉽게 구현할 수 있습니다.


15 - 3. C++ memory order 와 atomic 객체
  1) 메모리는 엄청 느리다.
  - 인텔의 i7-6700의 경우 RAM에서 읽어오는데 최소 42사이클 걸림
  - Cache를 써서 속도를 보완함.
  - L1, L2, L3로 갈수록 느리고 크기가 커짐
  - Cache hit 빈도가 높을수록 빠르게 연산함

  2) 컴퓨터는 우리의 명령을 그대로 수행하지 않는다.
  - CPU 파이프라이닝을 위해 명령어를 재배치 한다.
  - Cache에 있는 것을 먼저 처리하기도 한다.

  3) 무엇을 믿어야 하는가?
  - C++의 모든 객체들은 수정 순서(modification order) 라는 것을 정의할 수 있다.
  - 여러 쓰레드에서 한 변수가 변화하는 값을 관찰할 때,
    순서가 거꾸로 되지만 않으면 괜찮다고 본다. 최종값은 같아야 함.
  - CPU 캐시가 각 코어별로 존재하기 때문
  - C++에서는 이를 동기화 할 수 있는 도구를 제공한다.

  4) 원자성(atomicity)
  - C++에서 모든 쓰레드들이 수정 순서에 동의해야만 하는 경우는 모든 연산들이 '원자적'일 때이다.
  - '원자적' 이란 CPU가 명령어 1개로 처리하는 명령으로, 다른 쓰레드가 끼어들 여지가 전혀 없는 연산
  - 올바른 연산을 위해 굳이 mutex가 필요 없다.
  - std::atomic<int> counter(0);
    => lock add DWORD PTR [rdi], 1

  - atomic 객체의 연산들이 과연 정말 원자적으로 구현될 수 있는지는 is_lock_free()를 호출해서 확인한다.

  5) memory_order
  - atomic 객체들의 경우 원자적 연산시 메모리 접근방식을 설정 가능
  - memory_order_relaxed 는 앞서 말했듯이, 메모리 연산들 사이에서 어떠한 제약조건도 없다고 하였습니다.
    다시 말해 서로 다른 변수의 relaxed 메모리 연산은 CPU 마음대로 재배치 할 수 있습니다
    (단일 쓰레드 관점에서 결과가 동일하다면).

  - memory_order_acquire와 memory_order_release
    : producer-consumer 패턴에서 쓰는 좀더 엄격한 기준

  - memory_order_acq_rel

  - memory_order_seq_cst
    : memory_order_seq_cst 는 메모리 명령의 순차적 일관성(sequential consistency) 을 보장해줍니다.
    : 순차적 일관성이란, 메모리 명령 재배치도 없고, 모든 쓰레드에서 모든 시점에 동일한 값을 관찰할 수 있는,
      여러분이 생각하는 그대로 CPU 가 작동하는 방식이라 생각하면 됩니다.
    : ARM 같은 특정 아키텍쳐에서는 매우 비싼 동기화 비용이 든다.

  6) 생각 해보기
  - 문제 1
    std::atomic<bool> 을 사용해서 lock() 과 unlock() 을 만들어보세요.
    참고로 compare_exchange_strong 함수를 사용하는 것이 도움이 됩니다. compare_exchange_strong 은 아래와 같이 생겼습니다.

    bool compare_exchange_strong(
      T& expected, T desired, std::memory_order order = std::memory_order_seq_cst);

  - 문제 2
    위는 atomic_flag 의 test_and_set 함수를 이용해서도 동일하게 만들 수 있습니다. 한 번 다시 만들어보세요!
    atomic_flag 는 std::atomic<bool> 과 비슷하게 true 혹은 false 만 가질 수 있지만,
    atomic_flag 는 is_lock_free 가 언제나 참임이 보장됩니다.
    반면에 std::atomic<bool> 은 그렇지 않습니다. (정확히 말하자면 모든 atomic 객체들은 is_lock_free 가 참인 것이 보장되지 않습니다.)


15 - 4. C++ future, promise, packaged_task, async
  1) synchronous와 asynchronous 실행
  - HDD 읽기와 다른 Computation을 병행하는 등의 작업
  - 프로그램의 실행이, 한 갈래가 아니라 여러 갈래로 갈라져서 동시에 진행되는 것을
    비동기적(asynchronous) 실행 이라고 부릅니다.

  2) std::promise와 std::future
  - 내가 어떤 쓰레드 T 를 사용해서, 비동기적으로 값을 받아내겠다 라는 의미는,
    미래에 (future) 쓰레드 T 가 원하는 데이터를 돌려 주겠다 라는 약속 (promise) 라고 볼 수 있습니다.
  - std::promise<string> p;
    std::future<string> data = p.get_future();
  - promise 는 생산자-소비자 패턴에서 마치 생산자 (producer) 의 역할을 수행하고,
    future 는 소비자 (consumer) 의 역할을 수행한다고 보면 됩니다.
  - wait_for 을 사용하면 정해진 시간만 기다리고 그냥 진행 가능
    : future_status 객체를 리턴하는데, future_status::ready, timeout, deferred의 3가지 값이 있음

  3) shared_future
  - future의 경우 딱 한번만 get을 할 수 있음. 객체가 이동하기 때문.
  - 여러 쓰레드에서 future을 get 하려면 shared_future를 쓴다.

  4) packaged_task
  - promise-future 패턴을 asynchronous functor의 리턴값에 간단히 적용할 수 있음
  - std::packaged_task<int(int)> task(some_task);
    std::future<int> start = task.get_future();

    thread t(std::move(task), 5);

  5) std::async
  - promise 나 packaged_task 는 비동기적으로 실행을 하기 위해서는, 쓰레드를 명시적으로 생성해서 실행해야만 했습니다.
    하지만 std::async 에 어떤 함수를 전달한다면, 아예 쓰레드를 알아서 만들어서 해당 함수를 비동기적으로 실행하고,
    그 결과값을 future 에 전달합니다.
  - std::future<int> lower_half_future =
     std::async(std::launch::async, sum, cref(v), 0, v.size() / 2);

     - std::launch::async : 바로 쓰레드를 생성해서 인자로 전달된 함수를 실행한다.
     - std::launch::deferred : future 의 get 함수가 호출되었을 때 쓰레드를 생성해서 실행한다.

  6) 생각 해보기 문제


15 - 5. C++ 쓰레드풀(ThreadPool) 만들기


16 - 1. C++ 유니폼 초기화(Uniform Initialization)
  1) 균일한 초기화 (Uniform Initialization)
    - A a(); => C++ 의 컴파일러는 함수의 정의처럼 보이는 것들은 모두 함수의 정의로 해석
    - 생성자를 호출하기 위해 ()를 사용하는 대신에 {}를 사용
    - 큰 차이점은 일부 암시적 타입 변환들을 불허함
      - 부동 소수점 타입에서 정수 타입으로의 변환 (우리의 예시지요)
      - long double 에서 double 혹은 float 으로의 변환, double 에서 float 으로의 변환.
      - 정수 타입에서 부동 소수점 타입으로의 변환
    - 함수 리턴 시에 굳이 생성하는 객체의 타입을 다시 명시하지 않아도 됨

  2) 초기화자 리스트 (Initializer list)
    - initializer_list 는 우리가 {} 를 이용해서 생성자를 호출할 때,
      클래스의 생성자들 중에 initializer_list 를 인자로 받는 생성자가 있다면 전달됩니다.
    - std::vector<int> v = {1, 2, 3, 4, 5};
    - 생성자들 중에서 initializer_list 를 받는 생성자가 있다면 주의할 점
      => 만일 {}를 이용해서 객체를 생성할 경우 생성자 오버로딩 시에 해당 함수가 최우선으로 고려됨
      => vector v{10}; => 10을 보관하는 벡터 생성
	  => 컴파일러가 최선을 다해서 해당 생성자와 매칭시키려고 노력

  3) initializer_list 와 auto
    - auto x = {arg1, arg2...} 형태의 경우 arg1, arg2 ... 들이 모두 같은 타입이라면 x 는 std::initializer_list<T> 로 추론됩니다.
    - auto x {arg1. arg2, ...} 형태의 경우 만일 인자가 단 1 개라면 인자의 타입으로 추론되고, 여러 개일 경우 오류를 발생시킵니다.

 정리:
  - 유니폼 초기화 ({} 를 이용한 생성자 호출) 를 통해서 인자 없는 생성자가
    함수의 정의로 오해되는 일을 막을 수 있으며 initializer_list 를 만들어 전달할 수 있습니다.
  - initializer_list 를 통해서 객체를 간단하게 생성할 수 있습니다.


16 - 2. constexpr 와 함께라면 컴파일 타임 상수는 문제없어
  - constexpr : 객체나 함수 앞에 붙이면 해당 객체나 함수의 리턴값을 컴파일 타임에 값을 알 수 있다는 뜻
  - 컴파일 타임에 어떠한 식의 값을 결정할 수 있다면 Constant expression이라고 함
    특히 Integral constant expression의 쓰임이 많다

  1) constexpr vs const
    - const 로 정의된 상수들은 굳이 컴파일 타임에 그 값을 알 필요가 없다.
	- constexpr은 항상 const 이지만, const는 constexpr이 아니다.

  2) constexpr 함수
    - A<factorial(5)> a; => 기존에는 TMP를 활용해야 했다.
	- 하지만 함수의 리턴 타입에 constexpr 을 추가한다면 조건이 맞을 때,
	  해당 함수의 리턴값을 컴파일 타임 상수로 만들어버릴 수 있습니다.
    - 제약조건:
	  - goto 문 사용
	  - 예외 처리 (try 문; C++ 20 부터 가능하게 바뀌었습니다.)
	  - 리터럴 타입이 아닌 변수의 정의
	  - 초기화 되지 않는 변수의 정의
	  - 실행 중간에 constexpr 이 아닌 함수를 호출하게 됨
	- constexpr 함수에 인자로 컴파일 타임 상수가 아닌 값을 전달하면 일반함수로 동작

  3) 리터럴 타입: 컴파일러가 컴파일 타임에 정의할 수 있는 타입
    - void 형
	- 스칼라 타입 (char, int, bool, long, float, double) 등등
	- 레퍼런스 타입
	- 리터럴 타입의 배열
	- 혹은 아래 조건들을 만족하는 타입
	  - 디폴트 소멸자를 가지고
	  - 다음 중 하나를 만족하는 타입
	    - 람다 함수
        - Arggregate 타입 (사용자 정의 생성자, 소멸자가 없으며 모든 데이터 멤버들이 public)
	      쉽게 말해 pair 같은 애들을 이야기함
		- constexpr 생성자를 가지며 복사 및 이동 생성자가 없음

	- C++ 14 부터 constexpr 생성자를 지원함으로써 사용자들이 리터럴 타입들을 직접 만들 수 있게 되었습니다.

  4) constexpr 생성자
  - constexpr 생성자는 일반적인 constexpr 메소드의 제약 조건이 모두 적용됨
  - 생성자의 인자들은 반드시 리터럴 타입이어야 하고, 다른 클래스를 가상 상속받을 수 없음

  5) if constexpr
  - if constexpr 은 조건이 반드시 bool 로 타입 변환될 수 있어야 하는 컴파일 타임 상수식이어야만 합니다.
  - 그 대신, if constexpr 이 참이라면 else 에 해당하는 문장은 컴파일 되지 않고 (완전히 무시)
    마찬가지로 if constexpr 이 거짓이라면 else 에 해당 하는 부분만 컴파일 됩니다.

  6) 뭘 배웠지?
  - constexpr 을 통해 컴파일 타임 상수인 객체를 선언할 수 있다.
  - const 와 constexpr 은 다르다. const 는 컴파일 타임에 상수일 필요가 없다! (const 인 애들 중에서 constexpr 이 있다고 생각하면 된다)
  - constexpr 로 정의된 함수는 인자로 리터럴을 전달하였을 때 컴파일 타임 상수를 리턴한다.
  - constexpr 생성자를 가진 클래스는 constexpr 객체를 생성할 수 있다.

16 - 3. 타입을 알려주는 키워드 decltype 와 친구 std::declval
  1) decltype
  - decltype 키워드는 C++ 11 에 추가된 키워드로, decltype 라는 이름의 함수 처럼 사용됩니다.
  - decltype 는 함수와는 달리, 타입을 알고자 하는 식의 타입으로 치환되게 됩니다.
  - int a = 3;
    decltype(a) b = 2;  // int

  - 위와 같이 decltype 에 전달된 식이 '괄호로 둘러쌓이지 않은 식별자 표현식(id-expression) 이라면 해당 식의 타입을 얻을 수 있음
  - id-expression : 어떠한 연산을 하지 않고 단순히 객체 하나만을 가리키는 식

  - decltype 에	식별자 표현식이 아닌 식은 전달하면?
    - 만일 식의 값 종류가 xvalue 라면 decltype 는 T&& 가 됩니다.
    - 만일 식의 값 종류가 lvalue 라면 decltype 는 T& 가 됩니다.
    - 만일 식의 값 종류가 prvalue 라면 decltype 는 T 가 됩니다.

  2) Value Category
  - 모든 C++ expression 에는 '타입'과 '값 카테고리' 두 가지 정보가 항상 따라다닌다.
  - 값 카테고리를 따질때
    - 정체를 알 수 있는가?
      정체를 알 수 있다는 말은 해당 식이 어떤 다른 식과 같은 것인지 아닌지를 구분할 수 있다는 말입니다.
      일반적인 변수라면 주소값을 취해서 구분할 수 있겠고, 함수의 경우라면 그냥 이름만 확인해보면 될 것입니다.

    - 이동 시킬 수 있는가?
      해당 식을 다른 곳으로 안전하게 이동할 수 있는지의 여부를 묻습니다.
      즉 해당 식을 받는 이동 생성자, 이동 대입 연산자 등을 사용할 수 있어야만 합니다.


                          이동 시킬 수 있다           이동 시킬 수 없다
  정체를 알 수 있다           xvalue                       lvalue
  정체를 알 수 없다           prvalue                      쓸모 없음

  3) lvalue
  - 이름을 가진 대부분의 객체들은 모두 lvalue 이다.
    - 변수, 함수의 이름, 어떤 타입의 데이터 멤버 (예컨대 std::endl, std::cin) 등등
    - 좌측값 레퍼런스를 리턴하는 함수의 호출식. std::cout << 1 이나 ++it 같은 것들
    - a = b, a += b, a *= b 같이 복합 대입 연산자 식들
    - ++a, --a 같은 전위 증감 연산자 식들
    - a.m, p->m 과 같이 멤버를 참조할 때. 이 때 m 은 enum 값이거나 static 이 아닌 멤버 함수인 경우 제외. (아래 설명 참조)
    - a[n] 과 같은 배열 참조 식들
    - 문자열 리터럴 "hi"

  - lvalue는 모두 &를 써서 주소값을 알아낼 수 있다.
  - ++i 나 &std::endl 모두 올바른 작업

  - void f(int&& a) {
      a;  // <-- ?
    }
    f(3);

  - a의 타입은 우측값 레퍼런스 이지만, 값 카테고리는 lvalue 이다.


  4) prvalue
  - int f() { return 10; }
    f();  // <-- ?

  - f() 는 주소값을 취할 수 없지만 우측값 레퍼런스에 붙을 수 있으므로 prvalue 이다.
  - prvalue의 종류
    - 문자열 리터럴을 제외 한 모든 리터럴들. 42, true, nullptr 같은 애들
    - 레퍼런스가 아닌 것을 리턴하는 함수의 호출식. 예를 들어서 str.substr(1, 2), str1 + str2
    - 후위 증감 연산자 식. a++, a--
    - 산술 연산자, 논리 연산자 식들. a + b, a && b, a < b 같은 것들을 말합니다.
      물론, 이들은 연산자 오버로딩 된 경우들 말고 디폴트로 제공되는 것들을 말합니다.
    - 주소값 연산자 식 &a
    - a.m, p->m 과 같이 멤버를 참조할 때. 이 때 m 은 enum 값이거나 static 이 아닌 멤버 함수여야함.
    - this
    - enum 값
    - 람다식 []() { return 0;}; 과 같은 애들.

  - prvalue 는 주소값을 취할 수 없고, 식의 좌측에 올 수 없다.
  - 하지만 우측값 레퍼런스와 상수 좌측값 레퍼런스를 초기화 하는데 사용할 수 있습니다.
    - const int& r = 42;
    - int&& rr = 42;
    - // int& rrr = 42; <-- 불가능

  5) xvalue
  - 좌측값 처럼 정체가 있지만 이동도 시킬 수 있는 것들을 생각해봐야 합니다.
  - 우측값 레퍼런스를 리턴하는 함수의 호출식: 예를 들어 std::move(x)
    - template <class T>
      constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept;

  - 다시 decltype 으로 돌아와서
    - 만일 식의 값 종류가 xvalue 라면 decltype 는 T&& 가 됩니다.
    - 만일 식의 값 종류가 lvalue 라면 decltype 는 T& 가 됩니다.
    - 만일 식의 값 종류가 prvalue 라면 decltype 는 T 가 됩니다.

    - int a, b;
      decltype(a + b) c;  // c 의 타입은?

     => a+b 는 prvalue 이므로 a+b의 실제 타입인 int로 추론됨

    - int a;
      decltype((a)) b;  // b 의 타입은?

      => (a) 는 식별자 표현식이 아니기 때문에 어느 값 카테고리에 들어가는지 생각해봐야 합니다.
         쉽게 생각하면 &(a) 와 같이 주소값 연산자를 적용할 수 있고,
	 당연히도 이동 불가능 이므로 lvalue 가 됩니다.
	 따라서 b 는 int 가 될 것이라는 예상과는 다르게 int& 로 추론됩니다!

  6) decltype 의 쓰임새
  - auto 는 const를 떼버리지만 decltype은 const까지 제대로 추론
  - auto 는 배열을 암시적 포인터로 변환, decltype의 경우 배열 타입 그대로 추론

  - template <typename T, typename U>
    auto add(T t, U u) -> decltype(t + u) {
      return t + u;
    }

  7) std::declval

  8) 뭘 배웠지?
  - decltype 키워드를 통해서 우리가 원하는 식의 타입을 알 수 있습니다.
    만일 해당 식이 단순한 식별자 표현식 (identifier expression) 이라면 그냥 그 식의 타입으로 치환됩니다.
    그 이외의 경우라면 해당 식의 값 카테고리가 뭐냐에 따라서 decltype 의 타입이 정해집니다.

  - C++ 의 모든 식에는 두 가지 꼬리표가 따라다니는데 하나는 타입이고, 다른 하나는 값 카테고리 입니다.

  - 값 카테고리는 크게 3 가지 종류로 lvalue, prvalue, xvalue 가 있습니다.

  - std::declval 함수를 사용해서 원하는 타입의 생성자 호출을 우회해서 멤버 함수의 타입에 접근할 수 있습니다.





