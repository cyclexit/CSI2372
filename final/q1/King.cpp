#include "King.h"

King::King(int clr, int r, char c) : Piece(clr, r, c) {}

bool King::move(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  // diagonal
  if ((r == row + 1 && c == column + 1)
      || (r == row - 1 && c == column - 1)
      || (r == row + 1 && c == column - 1)
      || (r == row - 1 && c == column + 1)) {
        return true;
  }

  return false;
}
