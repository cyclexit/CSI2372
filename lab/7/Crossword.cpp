#include "Crossword.h"

Crossword::Crossword() {
  rows = kDefaultRows;
  columns = kDefaultColumns;
  init_state(solved_state, rows, columns);
  init_state(current_state, rows, columns);
}

Crossword::Crossword(int n, int m) {
  rows = n;
  columns = m;
  init_state(solved_state, rows, columns);
  init_state(current_state, rows, columns);
}

bool Crossword::add_questions(const std::string& question,
                              const std::string& answer,
                              int row,
                              int column,
                              bool horizontal) {
  Question q;
  q.description = question;
  q.answer = answer;
  q.row = row;
  q.column = column;
  q.horizontal = horizontal;
  // check the length
  if (horizontal && column + q.answer.size() > columns) {
    return false;
  }
  if (!horizontal && row + q.answer.size() > rows) {
    return false;
  }
  // check the cross
  // update the solve_state
  return true;
}

std::ostream& operator<<(std::ostream& out, const Crossword& crossword) {
  out << "Puzzle:" << std::endl;
  for (int i = 0; i < crossword.rows; ++i) {
    out << crossword.current_state[i] << std::endl;
  }

  out << "Questions:" << std::endl;
  for (const Question& q : crossword.questions) {
    out << q << std::endl;
  }
  return out;
}

void Crossword::init_state(std::vector<std::string>& state,
                           int rows,
                           int columns) {
  state.resize(rows + 1, std::string(columns + 1, ' '));
  for (int col = 0; col < columns; ++col) {
    if (col) state[0][col] = col + '0';
  }
  for (int row = 0; row < rows; ++row) {
    if (row) state[row][0] = row + '0';
  }
}

bool Crossword::is_same_char(char ch1, char ch2) {
  return (ch1 == ch2) || (ch1 == (ch2 - 32));
}
