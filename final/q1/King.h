#ifndef FINAL_KING_H_
#define FINAL_KING_H_

#include "Piece.h"

class King : public Piece {
 public:
  King() = default;
  King(int clr, int r, char c);
  ~King() = default;

  bool is_move_valid(int r, char c) override;
};

#endif // FINAL_KING_H_
