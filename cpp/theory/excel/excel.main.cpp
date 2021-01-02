
#include <iostream>
#include <fstream>
#include "utils.h"

namespace MyExcel {

class Table;

class Cell {
 protected:
  int x, y;
  Table* table;

  string data;

 public:
  virtual string stringify();
  virtual int to_numeric();

  Cell(string data, int x, int y, Table* table);
};

Cell::Cell(string data, int x, int y, Table* table)
    : data(data), x(x), y(y), table(table) {}

string Cell::stringify() { return data; }
int Cell::to_numeric() { return 0; }

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

Table::Table(int max_row_size, int max_col_size)
    : max_row_size(max_row_size), max_col_size(max_col_size) {
  data_table = new Cell**[max_row_size];
  for (int i = 0; i < max_row_size; i++) {
    data_table[i] = new Cell*[max_col_size];
    for (int j = 0; j < max_col_size; j++) {
      data_table[i][j] = NULL;
    }
  }
}

Table::~Table() {
  for (int i = 0; i < max_row_size; i++) {
    for (int j = 0; j < max_col_size; j++) {
      if (data_table[i][j]) delete data_table[i][j];
    }
  }
  for (int i = 0; i < max_row_size; i++) {
    delete[] data_table[i];
  }
  delete[] data_table;
}

void Table::reg_cell(Cell* c, int row, int col) {
  if (!(row < max_row_size && col < max_col_size)) return;

  if (data_table[row][col]) {
    delete data_table[row][col];
  }
  data_table[row][col] = c;
}

int Table::to_numeric(const string& s) {
  // Cell 이름으로 받는다.
  int row = s[0] - 'A';
  int col = atoi(s.c_str() + 1) - 1;

  if (row < max_row_size && col < max_col_size) {
    if (data_table[row][col]) {
      return data_table[row][col]->to_numeric();
    }
  }
  return 0;
}
int Table::to_numeric(int row, int col) {
  if (row < max_row_size && col < max_col_size && data_table[row][col]) {
    return data_table[row][col]->to_numeric();
  }
  return 0;
}
string Table::stringify(const string& s) {
  // Cell 이름으로 받는다.
  int col = s[0] - 'A';
  int row = atoi(s.c_str() + 1) - 1;

  if (row < max_row_size && col < max_col_size) {
    if (data_table[row][col]) {
      return data_table[row][col]->stringify();
    }
  }
  return 0;
}
string Table::stringify(int row, int col) {
  if (row < max_row_size && col < max_col_size && data_table[row][col]) {
    return data_table[row][col]->stringify();
  }
  return "";
}
std::ostream& operator<<(std::ostream& o, Table& table) {
  o << table.print_table();
  return o;
}

class TxtTable : public Table {
  string repeat_char(int n, char c);

  // 숫자로 된 열 번호를 A, B, .... Z, AA, AB, ...  이런 순으로 매겨준다.
  string col_num_to_str(int n);

 public:
  TxtTable(int row, int col);

  // 텍스트로 표를 깨끗하게 출력해준다.
  string print_table();
};

TxtTable::TxtTable(int row, int col) : Table(row, col) {}

// 텍스트로 표를 깨끗하게 출력해준다.
string TxtTable::print_table() {
  string total_table;

  int* col_max_wide = new int[max_col_size];
  for (int i = 0; i < max_col_size; i++) {
    unsigned int max_wide = 2;
    for (int j = 0; j < max_row_size; j++) {
      if (data_table[j][i] &&
          data_table[j][i]->stringify().length() > max_wide) {
        max_wide = data_table[j][i]->stringify().length();
      }
    }
    col_max_wide[i] = max_wide;
  }
  // 맨 상단에 열 정보 표시
  total_table += "    ";
  int total_wide = 4;
  for (int i = 0; i < max_col_size; i++) {
    if (col_max_wide[i]) {
      int max_len = std::max(2, col_max_wide[i]);
      total_table += " | " + col_num_to_str(i);
      total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

      total_wide += (max_len + 3);
    }
  }

  total_table += "\n";
  // 일단 기본적으로 최대 9999 번째 행 까지 지원한다고 생각한다.
  for (int i = 0; i < max_row_size; i++) {
    total_table += repeat_char(total_wide, '-');
    total_table += "\n" + std::to_string(i + 1);
    total_table += repeat_char(4 - std::to_string(i + 1).length(), ' ');

    for (int j = 0; j < max_col_size; j++) {
      if (col_max_wide[j]) {
        int max_len = std::max(2, col_max_wide[j]);

        string s = "";
        if (data_table[i][j]) {
          s = data_table[i][j]->stringify();
        }
        total_table += " | " + s;
        total_table += repeat_char(max_len - s.length(), ' ');
      }
    }
    total_table += "\n";
  }

  return total_table;
}

string TxtTable::repeat_char(int n, char c) {
  string s = "";
  for (int i = 0; i < n; i++) s.push_back(c);

  return s;
}
// 숫자로 된 열 번호를 A, B, .... Z, AA, AB, ...  이런 순으로 매겨준다.
string TxtTable::col_num_to_str(int n) {
  string s = "";
  if (n < 26) {
    s.push_back('A' + n);
  } else {
    char first = 'A' + n / 26 - 1;
    char second = 'A' + n % 26;

    s.push_back(first);
    s.push_back(second);
  }

  return s;
}

}

// 생략
int main() {
  MyExcel::TxtTable table(5, 5);
  std::ofstream out("test.txt");

  table.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &table), 0, 0);
  table.reg_cell(new MyExcel::Cell("C++", 0, 1, &table), 0, 1);

  table.reg_cell(new MyExcel::Cell("Programming", 1, 1, &table), 1, 1);
  std::cout << std::endl << table;
  out << table;
}