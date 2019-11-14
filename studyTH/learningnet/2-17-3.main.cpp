#include <iostream>

class Base
{
public:
    virtual void foo() {}
    virtual void goo() {}
    virtual void hoo() {}
};

class Derived : public Base
{
public:
    virtual void foo() {}                // 1
    virtual void goo() override {}       // 2
    virtual void hoo() override final {} // 3
};

class Derived2 : public Derived
{
public:
            void foo() override {}  // 4
            void goo()  {}      // 5
    // virtual void hoo() override {}      // 6
};

int main() {

}