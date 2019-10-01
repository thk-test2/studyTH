#include <iostream>

class MyString {
public:
        MyString(const char c) : str_(nullptr), len_(0) {
            str_ = new char;
            *str_ = c;
            len_++;
        }

        MyString(const char* c) : str_(nullptr), len_(0) {
            const char* origin = c;
            while(*c) {
                len_++;
                c++;
            }
            c = origin;

            str_ = new char[len_+1];
            int i = 0;
            while(*c) {
                str_[i] = *c;
                i++;
                c++;
            }
        }

        ~MyString() {
            len_ == 1 ? delete str_ : delete [] str_;
        }

        char * concate(MyString str2) {
            char * original = str_;

            int new_len = len_ + str2.len();
            str_ = new char[new_len];

            int i = 0;
            char * original2 = original;
            while(*original) {
                str_[i] = *original;
                i++;
                original++;
            }
            delete [] original2;

            char * pstr2 = str2.str();
            while (*pstr2) {
                str_[i] = *pstr2;
                i++;
                pstr2++;
            }
            len_ = i;
            return str_;
        }

        bool compare(MyString str2) {
            if (len_ != str2.len())
                return false;
            
            char * pstr2 = str2.str();
            bool ans = true;
            for (int i = 0; i < len_ ; i++)
                if( *str_ != *pstr2 ) {
                    ans = false;
                    break;
                }
            return ans;
        }

        inline char * str() { return str_; }
        inline int len() { return len_; }

private:
    char * str_;
    int len_;
};

int main() {
    MyString s1('a');
    MyString s2("asdf");
    MyString s3("zxcv");

    std::cout << s1.str() << std::endl;
    std::cout << s2.str() << std::endl;

    s2.concate(s3);

    std::cout << s2.str() << std::endl;
    std::cout << s2.len() << std::endl;

    std::cout << s2.compare("asdfzxcv") << std::endl;

    return 0;
}