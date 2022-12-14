#ifndef FINAL_KING_H_
#define FINAL_KING_H_

#include "Piece.h"

class King : public Piece {
 public:
  King() = default;
  ~King() = default;

  bool move(int r, char c) override;
};

#endif // FINAL_KING_H_
