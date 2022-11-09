#include "Crossword.h"

Crossword::Crossword() {
  rows = kDefaultRows;
  columns = kDefaultColumns;
  questions.resize(rows);
  solved_state.resize(rows, std::vector<std::string>(columns, " "));
  current_state.resize(rows, std::vector<std::string>(columns, " "));
}

Crossword::Crossword(int n, int m) {
  rows = n;
  columns = m;
  questions.resize(rows);
  solved_state.resize(rows, std::vector<std::string>(columns, " "));
  current_state.resize(rows, std::vector<std::string>(columns, " "));
}
