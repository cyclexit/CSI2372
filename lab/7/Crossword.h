#ifndef LAB_7_CROSSWORD_H_
#define LAB_7_CROSSWORD_H_

#include <iostream>
#include <string>
#include <vector>

struct Question {
  int row;
  int col;
  std::string description;
  bool horizontal;

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

 private:
  // constants
  static constexpr int kDefaultRows = 10;
  static constexpr int kDefaultColumns = 10;
  
  // members
  int rows;
  int columns;

};

#endif // LAB_7_CROSSWORD_H_
