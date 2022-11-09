#include "Crossword.h"

Crossword::Crossword() {
  rows = kDefaultRows;
  columns = kDefaultColumns;
  questions.resize(rows + 1);
  solved_state.resize(rows + 1, std::vector<std::string>(columns + 1, " "));
  current_state.resize(rows + 1, std::vector<std::string>(columns + 1, " "));
}

Crossword::Crossword(int n, int m) {
  rows = n;
  columns = m;
  questions.resize(rows + 1);
  solved_state.resize(rows + 1, std::vector<std::string>(columns + 1, " "));
  current_state.resize(rows + 1, std::vector<std::string>(columns + 1, " "));
}

std::ostream& operator<<(std::ostream& out, const Crossword& crossword) {
  return out;
}
