#include <iostream>

template<typename Type> class Singleton
{
protected:
    Singleton() = default;
private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    struct PWrapper
    {
        Type* instancePtr;
        PWrapper() : instancePtr(NULL) {}
        ~PWrapper() { delete instancePtr; }
    };

    template<typename... Args>
        static Type& getInstance(Args... args) 
        {
            if ( NULL == wrapper.instancePtr )
                wrapper.instancePtr = new Type{std::forward<Args>(args)...};
            return *(wrapper.instancePtr);
        }

        static PWrapper wrapper;
};
template <typename T> typename Singleton<T>::PWrapper Singleton<T>::wrapper;

class Mouse : public Singleton<Mouse>
{
public:
    Mouse() {}
    void print() {
        std::cout << "Mouse!" << std::endl;
    }
};

class Cursor : public Singleton<Cursor>
{
public:
    Cursor(int x, int y) {}
    void print() {
        std::cout << "Cursor!" << std::endl;
    }
};

int main()
{
    Mouse& c = Mouse::getInstance();
    c.print();

    Cursor& d = Cursor::getInstance(1, 2);
    d.print();
}
