#include <iostream>

class Table;

class Cell {
  Table* table;  // 어느 테이블에 속해있는지
  std::string data;
  int x, y;  // 테이블 에서의 위치
 public:
  Cell() { }
  Cell(const std::string& data) : data(data){};

  // added method
  std::string get_data() { return data; }
};

class Table {
  Cell*** data_base;  // 왜 3중 포인터 인지 잘 생각해보세요!
  int N, M;
  int count;
 public:
  Table();
  virtual std::string print_table() = 0;
  void reg_cell(Cell* c, int row, int col);  // Cell 을 등록한다
  std::string get_cell(int row,
                       int col);  // 해당 위치의 Cell 데이터를 얻는다.
  ~Table() { delete [] data_base; }

  Cell* operator[] (const int index) {
    return *data_base[index];
  }
};

Table::Table() : data_base(nullptr), N(10), M(10), count(0) { 
  *data_base = new Cell*[N];
  for (size_t i = 0; i < N; i++)
  {
    *data_base[i] = new Cell[M];
  }
}

void Table::reg_cell(Cell* c, int row, int col) {
  // if (data_base[row][col])
  //   delete data_base[row][col];

  int size_ = sizeof(Cell);

  data_base[row][col] = new Cell(*c);
  // *(*(data_base+row*size_)+col*size_) = new Cell(*c);

  count++;
}

std::string Table::get_cell(int row, int col) {
  return data_base[row][col]->get_data();
}

std::ostream& operator<<(std::ostream& o, Table& t) {
  o << t.print_table();
  return o;
}

class TextTable : public Table {

public:

  virtual std::string print_table() override {
    get_cell(1, 1);
  }
};

int main() {

  Table* t = new TextTable();
  Cell* testCell = new Cell("test");

  t->reg_cell(testCell, 1, 1);
  std::cout << t->print_table();
}