#ifndef FINAL_QUEEN_H_
#define FINAL_QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 public:
  Queen() = default;
  Queen(int clr, int r, char c);
  ~Queen() = default;

  bool is_move_valid(int r, char c) override;
};

#endif // FINAL_QUEEN_H_
