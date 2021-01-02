#include <iostream>

using namespace std;

class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{
};

int main()
{
	Animal a; // (A)
	Dog    d; // (B)
}