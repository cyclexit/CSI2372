#include "King.h"

King::King(int clr, int r, char c) : Piece(clr, r, c) {}

bool King::move(int r, char c) {
  if (!in_chessboard(r, c)) return false;

  return false;
}
