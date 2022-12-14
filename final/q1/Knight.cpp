#include "Knight.h"

bool Knight::is_move_valid(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  // top right
  if ((r == row + 2 && c == column + 1) ||
      (r == row + 1 && c == column + 2)) {
    return true;
  }

  // top left
  if ((r == row + 2 && c == column - 1) ||
      (r == row + 1 && c == column - 2)) {
    return true;
  }

  // bottom right
  if ((r == row - 2 && c == column + 1) ||
      (r == row - 1 && c == column + 2)) {
    return true;
  }

  // bottom left
  if ((r == row - 2 && c == column - 1) ||
      (r == row - 1 && c == column - 2)) {
    return true;
  }

  return false;
}

bool Knight::move(int r, char c) {
  if (is_move_valid(r, c)) {
    row = r;
    column = c;
    return true;
  }

  return false;
}
