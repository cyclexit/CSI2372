#include "Knight.h"

bool Knight::is_move_valid(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  

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
