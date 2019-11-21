#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// 아래 Point 에는 디폴트 생성자가 없습니다. 디폴트 생성자를 만들지 말고.
// 아래 상태에 과제를 진행해 주세요..
class Point
{
    int a_;
    int b_;
public:
    Point(int a, int b) : a_(a), b_(b) {}
    void print() {
        cout << a_ << ", " << b_ << endl;
    }
};

// 아래 main 함수가 실행되도록 Vector를 구현해야 합니다.
template<typename T> class Vector
{
    T* buff;
    int sz;    // size
    int capa;  // capacity ( 메모리 사용량)
public:
    Vector(int t_sz, T temp) {
        sz = t_sz;
        capa = sz;

        buff = static_cast<T*> (operator new(sz * sizeof(T)));
        for (int i = 0; i < sz ; ++i) {
            new (&buff[i])T(temp);
        }
    }
    Vector(initializer_list<T> temp_list) {
        sz = temp_list.size();
        capa = sz;

        buff = static_cast<T*> (operator new(sz * sizeof(T)));
        int i = 0;
        for (auto itr : temp_list) {
            new (&buff[i])T(itr);
            i++;
        }
    }
    ~Vector() {
        delete [] buff;
    }
    T& operator[] (int index) {
        if (index >= 0 && index < sz)
            return buff[index];
        cout << "invalid index" << endl;
    }
    Vector& resize(int new_size, T temp) {

        if (new_size > capa) {
            T* temp_buff = static_cast<T*> (operator new(new_size * sizeof(T)));
            for (int i = 0; i < sz ; ++i) {
                new (&temp_buff[i]) T(buff[i]);
            }
            for (int i = sz; i < new_size ; ++i) {
                new (&temp_buff[i]) T(temp);
            }
            buff = move(temp_buff);
            sz = new_size;
            capa = new_size;
        } else {
            for (int i = sz -1 ; i >= new_size ; --i) {
                buff[i].~T();
            }
            T* temp_buff = static_cast<T*> (operator new(new_size * sizeof(T)));
            for (int i = 0; i < new_size ; ++i) {
                new (&temp_buff[i]) T(buff[i]);
            }
            buff = move(temp_buff);
            sz = new_size;
        }
    }
    int size() { return sz; }
    int capacity() { return capa; }
};

int main()
{
    // 1. 아래 한줄이 실행되게 해주세요..
    // Point 10개를 위한 버퍼가 만들어져야 하고, Point(1,1)로 초기화 되어야 합니다.
    Vector<Point> v(10, Point(1,1));

    // // 2. 버퍼가 20개로 할당 되고 기존 10개는 이동(복사)하고,
    // // 새로운 10개는 Point(0,0)으로 초기화되게 하세요
    v.resize(20, Point(0,0));

    v[5].print();
    v[15].print();

    // // 3. 버퍼 크기를 다시 10개로 줄여 주세요. - 실제 메모리는 줄이지 말고, 객체만 파괴(소멸자 호출)해 주세요
    v.resize(10, Point(0,0));
    cout << v.size() << endl; // 10
    cout << v.capacity() << endl; // 20

    // // 4. initializer_list 추가하기.
    Vector<int> v2{ 1,2,3,4,5,6,7,8,9,10 };

    // // 5. ranged for 지원 하기
    // for (auto n : v2)
    // cout << n << endl; // 1,2,3,4,5,6,7,8,9,10
}