#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // STL의 함수 객체
#include <random>

using namespace std;

class Less {
public:
    bool operator()(int a, int b) {
       return a < b;
    }
};

template <typename T>
void printVector(vector<T> v) {
    for (const auto& n : v) {
        cout << n << ", ";
    }
}

class Random {
private:
    vector<int> numbers;
    mt19937 m_gen;
    uniform_int_distribution<int> m_dis;

public:
    Random() {
        random_device rd;
        m_gen = mt19937(rd());
        m_dis = uniform_int_distribution<int>(0, 99);
    }
    int operator()() {
        int n;
        while(1) {
            n = m_dis(m_gen);
            const vector<int>::iterator& itr = find(begin(numbers), end(numbers), n);
            if (itr == end(numbers))
                break;
        }
        return n;
    }
};

int main()
{
    vector<int> v;

    // 1. 난수를 10개 구해서 v에 넣으세요
    Random rc;
    for (int i = 0; i < 10 ; i++) {
        v.push_back(rc());
    }

    int cmd = 0;
    while (1)
    {
        cout << endl << "1. 모든 요소 출력" << endl;
        cout << "2. 오름 차순 정렬" << endl;
        cout << "3. 내림 차순 정렬" << endl;
        cout << "4. 선택 요소 삭제" << endl;
        cout << "5. 선택 요소 0으로 변경" << endl;
        cout << "6. 사이즈 20으로 변경" << endl;
        cout << "7. 프로그램 종료" << endl;
        cin >> cmd;

        // 2. cmd가 1이면 v의 모든 내용을 화면에 출력해 주세요
        if (cmd == 1) {
            printVector<int>(v);
        }
        // 3. cmd가 2이면 v를 오름 차순으로 정렬한 후 v의 내용을 화면 출력해 주세요
        // 비교 정책으로 함수 객체를 사용해서 만들어 주세요
        else if (cmd == 2) {
//            sort(v.begin(), v.end(), Less());
            sort(v.begin(), v.end(), less<int>());
        }
        // 4. cmd가 3이면 v를 내림 차순으로 정렬한 후 v의 내용을 화면 출력해 주세요
        // 비교 정책으로 람다 표현식을 사용해 주세요
        else if (cmd == 3) {
            sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
        }
        // 5. cmd가 4이면 또 다른 숫자를 하나 입력 받으세요.
        // 해당 숫자가 vector에 있으면 제거한후 vector를 다시 출력해 주세요
        else if (cmd == 4) {
            cout << "제거할 숫자 입력" << endl;
            int n; cin >> n;

            if (auto itr = find(v.begin(), v.end(), n); itr != v.end()) {
                v.erase(itr);
                printVector<int>(v);
            }
        }
        // 6. cmd가 5이면 또 다른 숫자를 하나 입력 받으세요.
        // 해당 숫자를 찾아서 0으로 변경한후 vector를 다시 출력해 주세요
        else if (cmd == 5) {
            cout << "변경할 숫자 입력" << endl;
            int n; cin >> n;

            if (auto itr = find(v.begin(), v.end(), n); itr != v.end()) {
                *itr = 0;
                printVector<int>(v);
            }
        }
        // 7. cmd가 6이면 v의 size를 20개로 늘린 후 v의 내용을 출력해 주세요
        else if (cmd == 6) {
            v.resize(20);
            printVector<int>(v);
        }
        else if (cmd == 7)
            break;
    }
    exit(0);
}
