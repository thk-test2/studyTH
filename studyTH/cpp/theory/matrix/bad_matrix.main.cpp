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

class IntMatrix3 {
private:
    int *** parr3_;
    int N, M, L;

public:
    IntMatrix3(int n, int m, int l) : N(n), M(m), L(l) {
        parr3_ = new int**[N];
        for(int i=0; i< N ; i++) {
            parr3_[i] = new int*[M];
            for(int j=0; j<M ; j++)
                parr3_[i][j] = new int[L];
        }
    };

    ~IntMatrix3() { delete [] parr3_; }

    void print() {
        for(int i=0 ; i < N ; i++)
            for(int j=0; j < M ; j++)
                for(int k=0; k < L ; k++)
                    std::cout << parr3_[i][j][k] << std::endl;
    }

    int** operator[] (const int index) {
        return parr3_[index];
    }
};

int main() {

    // IntMatrix arr(10);

    // arr[5] = 999; 
    // arr.print();

    IntMatrix2 arr2(3, 3);
    arr2[2][2] = 999;

    std::cout << arr2[2][2] << std::endl;

    IntMatrix3 arr3(3, 3, 3);
    arr3[1][1][1] = 999;

    std::cout << arr3[1][1][1] << std::endl;
}