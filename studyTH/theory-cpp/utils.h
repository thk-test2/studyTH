#include <iostream>

using namespace std;

class Vector {
  string* data;
  int capacity;
  int length;

 public:
  // 생성자
  Vector(int n = 1);

  // 맨 뒤에 새로운 원소를 추가한다.
  void push_back(string s);

  // 임의의 위치의 원소에 접근한다.
  string operator[](int i);

  // x 번째 위치한 원소를 제거한다.
  void remove(int x);

  // 현재 벡터의 크기를 구한다.
  int size();

  ~Vector();
};

Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

void Vector::push_back(string s) {
  if (capacity <= length) {
    string* temp = new string[capacity * 2];
    for (int i = 0; i < length; i++) {
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
  }

  data[length] = s;
  length++;
}

string Vector::operator[](int i) { return data[i]; }

void Vector::remove(int x) {
  for (int i = x + 1; i < length; i++) {
    data[i - 1] = data[i];
  }
  length--;
}

int Vector::size() { return length; }

Vector::~Vector() {
  if (data) {
    delete[] data;
  }
}

struct Node {
  Node* prev;
  string s;

  Node(Node* prev, string s) : prev(prev), s(s) {}
};

class Stack {
  struct Node {
    Node* prev;
    string s;

    Node(Node* prev, string s) : prev(prev), s(s) {}
  };

  Node* current;
  Node start;

 public:
  Stack();

  // 최상단에 새로운 원소를 추가한다.
  void push(string s);

  // 최상단의 원소를 제거하고 반환한다.
  string pop();

  // 최상단의 원소를 반환한다. (제거 안함)
  string peek();

  // 스택이 비어있는지의 유무를 반환한다.
  bool is_empty();

  ~Stack();
};

Stack::Stack() : start(NULL, "") { current = &start; }
void Stack::push(string s) {
  Node* n = new Node(current, s);
  current = n;
}
string Stack::pop() {
  if (current == &start) return "";

  string s = current->s;
  Node* prev = current;
  current = current->prev;

  // Delete popped node
  delete prev;
  return s;
}
string Stack::peek() { return current->s; }
bool Stack::is_empty() {
  if (current == &start) return true;
  return false;
}
Stack::~Stack() {
  while (current != &start) {
    Node* prev = current;
    current = current->prev;
    delete prev;
  }
}


