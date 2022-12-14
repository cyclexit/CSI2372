#include "queen.h"

Queen::Queen(int clr, int r, char c) : Piece(clr, r, c) {}

bool Queen::is_move_valid(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  // diagonal
  for (int i = 0; i < kMaxColumn; ++i) {
    
  }

  // cross
}

bool Queen::move(int r, char c) {
  if (is_move_valid(r, c)) {
    row = r;
    column = c;
    return true;
  }

  return false;
}
