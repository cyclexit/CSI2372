#include "Bishop.h"

Bishop::Bishop(int clr, int r, char c) : Piece(clr, r, c) {}

bool Bishop::is_move_valid(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  for (int i = 0; i < kMaxColumn; ++i) {
    // diagonal
    if ((r == row + i && c == column + i)
        || (r == row - i && c == column - i)
        || (r == row + i && c == column - i)
        || (r == row - i && c == column + i)) {
      return true;
    }
  }

  return false;
}
