#ifndef FINAL_ROOK_H_
#define FINAL_ROOK_H_

#include "Piece.h"

class Rook : public Piece {
 public:
  Rook() = default;
  Rook(int clr, int r, char c);
  ~Rook() = default;

  bool is_move_valid(int r, char c) override;
  bool move(int r, char c) override;
};

#endif // FINAL_ROOK_H_
