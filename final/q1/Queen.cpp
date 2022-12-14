#include "Queen.h"

Queen::Queen(int clr, int r, char c) : Piece(clr, r, c) {}

bool Queen::is_move_valid(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  for (int i = 0; i < kMaxColumn; ++i) {
    // diagonal
    if ((r == row + i && c == column + i)
        || (r == row - i && c == column - i)
        || (r == row + i && c == column - i)
        || (r == row - i && c == column + i)) {
      return true;
    }

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

bool Queen::move(int r, char c) {
  if (is_move_valid(r, c)) {
    row = r;
    column = c;
    return true;
  }

  return false;
}
