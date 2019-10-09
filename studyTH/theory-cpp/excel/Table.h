
#include "utils.cpp"

namespace MyExcel {

class Table;

class Cell {
 protected:
  int x, y;
  Table* table;

 public:
  virtual string stringify() = 0;
  virtual int to_numeric() = 0;

  Cell(int x, int y, Table* table);
};

class StringCell : public Cell {
  string data;

 public:
  string stringify();
  int to_numeric();

  StringCell(string data, int x, int y, Table* t);
};

class NumberCell : public Cell {
  int data;

 public:
  string stringify();
  int to_numeric();

  NumberCell(int data, int x, int y, Table* t);
};
class DateCell : public Cell {
  time_t data;

 public:
  string stringify();
  int to_numeric();

  DateCell(string s, int x, int y, Table* t);
};

class ExprCell : public Cell {
  string data;
  string* parsed_expr;

  Vector exp_vec;

  // 연산자 우선 순위를 반환합니다.
  int precedence(char c);

  // 수식을 분석합니다.
  void parse_expression();

 public:
  ExprCell(string data, int x, int y, Table* t);

  string stringify();
  int to_numeric();
};

class Table {
 protected:
  // 행 및 열의 최대 크기
  int max_row_size, max_col_size;

  // 데이터를 보관하는 테이블
  // Cell* 을 보관하는 2차원 배열이라 생각하면 편하다
  Cell*** data_table;

 public:
  Table(int max_row_size, int max_col_size);

  ~Table();

  // 새로운 셀을 row 행 col 열에 등록한다.
  void reg_cell(Cell* c, int row, int col);

  // 해당 셀의 정수값을 반환한다.
  // s : 셀 이름 (Ex. A3, B6 과 같이)
  int to_numeric(const string& s);

  // 행 및 열 번호로 셀을 호출한다.
  int to_numeric(int row, int col);

  // 해당 셀의 문자열을 반환한다.
  string stringify(const string& s);
  string stringify(int row, int col);

  virtual string print_table() = 0;
};

class TxtTable : public Table {
  string repeat_char(int n, char c);

  // 숫자로 된 열 번호를 A, B, .... Z, AA, AB, ...  이런 순으로 매겨준다.
  string col_num_to_str(int n);

 public:
  TxtTable(int row, int col);

  // 텍스트로 표를 깨끗하게 출력해준다.
  string print_table();
};

std::ostream& operator<<(std::ostream& o, Table& table) {
  o << table.print_table();
  return o;
}

}