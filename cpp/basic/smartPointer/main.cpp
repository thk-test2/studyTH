#include <iostream>

class Car
{
    int color;
public:
    ~Car() { std::cout << "~Car()" << std::endl; }

    void Go() { std::cout << "Car Go" << std::endl; }
};

template<typename T> class Ptr
{
    T* pObj;
public:
    Ptr(T* p = 0) : pObj(p) {}
    ~Ptr() { delete pObj; }

    T* operator->() { return pObj; }
    T& operator*() { return *pObj; }
};

int main()
{
    Ptr<Car> p = new Car; // Ptr p(new Car)

    p->Go(); // p.operator->()->GO()
    (*p).Go(); // (p.operator*()).Go()
}
