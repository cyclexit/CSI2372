#include "King.h"

King::King(int clr, int r, char c) : Piece(clr, r, c) {}

bool King::is_move_valid(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  // diagonal
  if ((r == row + 1 && c == column + 1)
      || (r == row - 1 && c == column - 1)
      || (r == row + 1 && c == column - 1)
      || (r == row - 1 && c == column + 1)) {
    return true;
  }

  // cross
  if ((r == row) && (c == column + 1 || c == column - 1)) {
    return true;
  }
  if ((c == column) && (r == row + 1 || r == row - 1)) {
    return true;
  }

  return false;
}
