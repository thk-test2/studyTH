#include <iostream>

class IntMatrix {

private:
    int * parr_;
    int N;

public:
    IntMatrix(int n) : N(n) {
        parr_ = new int[N];
    }

    ~IntMatrix() { delete [] parr_; }

    void print() {
        for(int i=0 ; i < N ; i++) {
            std::cout << parr_[i] << std::endl;
        }
    }

    int& operator[] (const int index) {
        return parr_[index];
    }
};

class IntMatrix2 {
private:
    int ** parr2_;
    int N, M;

public:
    IntMatrix2(int n, int m) : N(n), M(m) {
        parr2_ = new int*[N];
        for(int i=0; i< N ; i++) {
            parr2_[i] = new int[M];
        }
    };

    ~IntMatrix2() { delete [] parr2_; }

    void print() {
        for(int i=0 ; i < N ; i++)
            for(int j=0; j < M ; j++)
            std::cout << parr2_[i][j] << std::endl;
    }

    int* operator[] (const int index) {
        return parr2_[index];
    }
};

int main() {

    // IntMatrix arr(10);

    // arr[5] = 999; 
    // arr.print();

    IntMatrix2 arr2(3, 3);
    arr2[2][2] = 999;

    std::cout << arr2[2][2] << std::endl;
}