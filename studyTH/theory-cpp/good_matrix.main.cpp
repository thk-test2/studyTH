
#include <iostream>

namespace MyArray {
class Array;
class Int;

class Array {
  friend Int;

  const int dim;  // 몇 차원 배열 인지
  int* size;  // size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다.

  struct Address {
    int level;
    // 맨 마지막 레벨(dim - 1 레벨) 은 데이터 배열을 가리키고, 그 위 상위
    // 레벨에서는 다음 Address 배열을 가리킨다.
    void* next;
  };

  Address* top;

 public:
  class Iterator {
    int* location;
    Array* arr;

    friend Int;

   public:
    Iterator(Array* arr, int* loc = NULL) : arr(arr) {
      location = new int[arr->dim];
      for (int i = 0; i != arr->dim; i++)
        location[i] = (loc != NULL ? loc[i] : 0);
    }
    Iterator(const Iterator& itr) : arr(itr.arr) {
      location = new int[arr->dim];
      for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];
    }
    ~Iterator() { delete[] location; }
    // 다음 원소를 가리키게 된다.
    Iterator& operator++() {
      if (location[0] >= arr->size[0]) return (*this);

      bool carry = false;  // 받아 올림이 있는지
      int i = arr->dim - 1;
      do {
        // 어차피 다시 돌아온다는 것은 carry 가 true
        // 라는 의미 이므로 ++ 을 해야 한다.
        location[i]++;
        if (location[i] >= arr->size[i] && i >= 1) {
          // i 가 0 일 경우 0 으로 만들지 않는다 (이러면 begin 과 중복됨)
          location[i] -= arr->size[i];
          carry = true;
          i--;
        } else
          carry = false;

      } while (i >= 0 && carry);

      return (*this);
    }
    Iterator& operator=(const Iterator& itr) {
      arr = itr.arr;
      location = new int[itr.arr->dim];
      for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];

      return (*this);
    }
    Iterator& operator++(int) {
      ++(*this);
      return (*this);
    }
    bool operator!=(const Iterator& itr) {
      if (itr.arr->dim != arr->dim) return true;

      for (int i = 0; i != arr->dim; i++) {
        if (itr.location[i] != location[i]) return true;
      }

      return false;
    }
    Int operator*();
  };

  friend Iterator;
  Array(int dim, int* array_size) : dim(dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) size[i] = array_size[i];

    top = new Address;
    top->level = 0;

    initialize_address(top);
  }
  Array(const Array& arr) : dim(arr.dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) size[i] = arr.size[i];

    top = new Address;
    top->level = 0;

    initialize_address(top);
  }
  // address 를 초기화 하는 함수이다. 재귀 호출로 구성되어 있다.
  void initialize_address(Address* current) {
    if (!current) return;
    if (current->level == dim - 1) {
      current->next = new int[size[current->level]];
      return;
    }
    current->next = new Address[size[current->level]];
    for (int i = 0; i != size[current->level]; i++) {
      (static_cast<Address*>(current->next) + i)->level = current->level + 1;
      initialize_address(static_cast<Address*>(current->next) + i);
    }
  }
  void delete_address(Address* current) {
    if (!current) return;
    for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
      delete_address(static_cast<Address*>(current->next) + i);
    }

    delete[] current->next;
  }
  Int operator[](const int index);
  ~Array() {
    delete_address(top);
    delete[] size;
  }

  Iterator begin() {
    int* arr = new int[dim];
    for (int i = 0; i != dim; i++) arr[i] = 0;

    Iterator temp(this, arr);
    delete[] arr;

    return temp;
  }
  Iterator end() {
    int* arr = new int[dim];
    arr[0] = size[0];
    for (int i = 1; i < dim; i++) arr[i] = 0;

    Iterator temp(this, arr);
    delete[] arr;

    return temp;
  }
};
class Int {
  void* data;

  int level;
  Array* array;

 public:
  Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL)
      : level(_level), data(_data), array(_array) {
    if (_level < 1 || index >= array->size[_level - 1]) {
      data = NULL;
      return;
    }
    if (level == array->dim) {
      // 이제 data 에 우리의 int 자료형을 저장하도록 해야 한다.
      data = static_cast<void*>((
          static_cast<int*>(static_cast<Array::Address*>(data)->next) + index));
    } else {
      // 그렇지 않을 경우 data 에 그냥 다음 addr 을 넣어준다.
      data = static_cast<void*>(static_cast<Array::Address*>(
                                    static_cast<Array::Address*>(data)->next) +
                                index);
    }
  };

  Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

  operator int() {
    if (data) return *static_cast<int*>(data);
    return 0;
  }
  Int& operator=(const int& a) {
    if (data) *static_cast<int*>(data) = a;
    return *this;
  }

  Int operator[](const int index) {
    if (!data) return 0;
    return Int(index, level + 1, data, array);
  }
};
Int Array::operator[](const int index) {
  return Int(index, 1, static_cast<void*>(top), this);
}
Int Array::Iterator::operator*() {
  Int start = arr->operator[](location[0]);
  for (int i = 1; i <= arr->dim - 1; i++) {
    start = start.operator[](location[i]);
  }
  return start;
}
}  // namespace MyArray
int main() {
  int size[] = {2, 3, 4};
  MyArray::Array arr(3, size);

  MyArray::Array::Iterator itr = arr.begin();
  for (int i = 0; itr != arr.end(); itr++, i++) (*itr) = i;
  for (itr = arr.begin(); itr != arr.end(); itr++)
    std::cout << *itr << std::endl;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        arr[i][j][k] = (i + 1) * (j + 1) * (k + 1) + arr[i][j][k];
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        std::cout << i << " " << j << " " << k << " " << arr[i][j][k]
                  << std::endl;
      }
    }
  }
}