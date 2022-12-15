#ifndef FINAL_BISHOP_H_
#define FINAL_BISHOP_H_

#include "Piece.h"

class Bishop : public Piece {
 public:
  Bishop() = default;
  Bishop(int clr, int r, char c);
  ~Bishop() = default;

  bool is_move_valid(int r, char c) override;
};

#endif // FINAL_BISHOP_H_
