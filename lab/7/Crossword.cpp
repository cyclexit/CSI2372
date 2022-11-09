#include "Crossword.h"

Crossword::Crossword() {
  rows = kDefaultRows;
  columns = kDefaultColumns;
  questions.resize(rows + 1);
  init_state(solved_state, rows, columns);
  init_state(current_state, rows, columns);
}

Crossword::Crossword(int n, int m) {
  rows = n;
  columns = m;
  questions.resize(rows + 1);
  init_state(solved_state, rows, columns);
  init_state(current_state, rows, columns);
}

std::ostream& operator<<(std::ostream& out, const Crossword& crossword) {
  out << "Puzzle:" << std::endl;

  out << "Questions:" << std::endl;
  for (const Question& q : crossword.questions) {
    out << q << std::endl;
  }
  return out;
}

void Crossword::init_state(std::vector<std::vector<std::string>>& state,
                           int rows,
                           int columns) {
  state.resize(rows + 1, std::vector<std::string>(columns + 1, " "));
  for (int col = 0; col < columns; ++col) {
    if (col) state[0][col] = col;
  }
  for (int row = 0; row < rows; ++row) {
    if (row) state[row][0] = row;
  }
}
