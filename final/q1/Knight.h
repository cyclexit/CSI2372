#ifndef FINAL_KNIGHT_H_
#define FINAL_KNIGHT_H_

#include "Piece.h"

class Knight : public Piece {
 public:
  Knight() = default;
  Knight(int clr, int r, char c);
  ~Knight() = default;

  bool is_move_valid(int r, char c) override;
  bool move(int r, char c) override;
};

#endif // FINAL_KNIGHT_H_
