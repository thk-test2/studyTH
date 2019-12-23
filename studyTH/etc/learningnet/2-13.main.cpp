#include <iostream>

class Base
{
public:
    Base(int a) {}
};

class Derived : public Base
{
public:
    using Base::Base;
    Derived() {}
};

int main()
{
    Derived d(3);
}