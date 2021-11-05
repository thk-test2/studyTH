#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class String
{
    char* buff;
    int   size;
public:
    String(const char* s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff, s);
    }
    String(const String& s) : String(s.buff) { }
    ~String() { delete[] buff; }

    String& operator=(const String& s)
    {
        if (&s == this)
            return *this;
        delete[] buff; // s1 = s1 처럼 자기 자신을 대입할 때 문제가 됨

        size = s.size;
        buff = new char[size + 1];
        strcpy(buff, s.buff);

        return *this;
    }

    void printBufAdr() { printf("%p\n", buff); }

    friend ostream& operator<<(ostream& os, const String& s1);
};

ostream& operator<<(ostream& os, const String& s1)
{
    return os << s1.buff;
}

int main()
{
    String s1 = "hello";
    cout << s1 << endl; // operator<<(cout, s1)

    String s2 = s1;
    cout << s2 << endl;

    s1.printBufAdr();
    s2.printBufAdr();

    String s3 = "world";
    cout << s3 << endl;

    s3 = s1; // s3.operator=(s1)
    cout << s3 << endl;
}
