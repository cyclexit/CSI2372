#include "Piece.h"

Piece::Piece() : color(0), row(1), column('a') {}

Piece::Piece(int clr, int r, char c) : color(clr), row(r), column(c) {}

bool Piece::move(int r, char c) {
  if (is_move_valid(r, c)) {
    row = r;
    column = c;
    return true;
  }

  return false;
}
