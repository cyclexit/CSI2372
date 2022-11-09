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

bool Crossword::add_question(const std::string& question,
                              const std::string& answer,
                              int row,
                              int column,
                              bool horizontal) {
  if (!is_row_valid(row) || !is_column_valid(column)) {
    return false;
  }

  // validate the question according to direction
  if (horizontal) {
    // check the length
    if (column + answer.size() > columns) {
      return false;
    }
    // check the cross
    for (int i = 0; i < answer.size(); ++i) {
      if (answer != " " && answer[i] != solved_state[row][column + i]) {
        return false;
      }
    }
  } else {
    // check the length
    if (row + answer.size() > rows) {
      return false;
    }
    // check the cross
    for (int i = 0; i < answer.size(); ++i) {
      if (answer != " " && answer[i] != solved_state[row + i][column]) {
        return false;
      }
    }
  }

  // add the question
  Question q;
  q.description = question;
  q.answer = answer;
  q.row = row;
  q.column = column;
  q.horizontal = horizontal;
  questions.push_back(q);

  // update the solved_state
  if (horizontal) {
    for (int i = 0; i < answer.size(); ++i) {
      solved_state[row][column + i] = answer[i];
    }
  } else {
    for (int i = 0; i < answer.size(); ++i) {
      solved_state[row + i][column] = answer[i];
    }
  }

  return true;
}

std::ostream& operator<<(std::ostream& out, const Crossword& crossword) {
  out << "Puzzle:" << std::endl;
  for (int i = 0; i <= crossword.rows; ++i) {
    if (i > 0) out << " " << i;
    else out << " ";
  }
  out << std::endl;
  for (int i = 1; i <= crossword.rows; ++i) {
    out << i << " ";
    for (int j = 0; j < crossword.current_state[i].size(); ++j) {
      out << crossword.current_state[i][j] << " ";
    }
    out << std::endl;
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
}

bool Crossword::is_same_char(char ch1, char ch2) {
  return (ch1 == ch2) || (ch1 == (ch2 - 32));
}

bool Crossword::is_row_valid(int row) {
  return (1 <= row) && (row <= rows);
}

bool Crossword::is_column_valid(int column) {
  return (1 <= column) && (column <= columns);
}
