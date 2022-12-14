#include "Rook.h"

Rook::Rook(int clr, int r, char c) : Piece(clr, r, c) {}

bool Rook::is_move_valid(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  for (int i = 0; i < kMaxColumn; ++i) {
    // cross
    if ((r == row) && (c == column + i || c == column - i)) {
      return true;
    }
    if ((c == column) && (r == row + i || r == row - i)) {
      return true;
    }
  }

  return false;
}

bool Rook::move(int r, char c) {
  if (is_move_valid(r, c)) {
    row = r;
    column = c;
    return true;
  }

  return false;
}
