#ifndef LAB_7_CROSSWORD_H_
#define LAB_7_CROSSWORD_H_

#include <iostream>
#include <string>
#include <vector>

struct Question {
  int row;
  int col;
  bool horizontal;
  std::string description;
  std::string answer;
  bool solved = false;

  friend std::ostream& operator<<(std::ostream& out, const Question& q) {
    std::string direction = q.horizontal ? "Horizontal" : "Vertical";
    out << "(" << q.row << ", " << q.col << ") - "
        << q.description
        << " (" << direction <<")";
    return out;
  }
};

class Crossword {
 public:
  // ctors and dtors
  Crossword();
  Crossword(int n, int m);

  // methods
  bool add_questions(const std::string& question,
                     const std::string& answer,
                     int row,
                     int column,
                     bool horizontal);
  bool solve(int row, int column, const std::string& answer);

  // operators
  friend std::ostream& operator<<(std::ostream& out, const Crossword& crossword);

 private:
  // constants
  static constexpr int kDefaultRows = 10;
  static constexpr int kDefaultColumns = 10;
  
  // members
  int rows;
  int columns;
  std::vector<Question> questions;
  std::vector<std::string> solved_state;
  std::vector<std::string> current_state;

  // methods
  void init_state(std::vector<std::string>& state,
                  int rows,
                  int columns);
};

#endif // LAB_7_CROSSWORD_H_
