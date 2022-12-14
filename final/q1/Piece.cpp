#include "Piece.h"

Piece::Piece() : color(0), row(1), column('a') {}

Piece::Piece(int clr, int r, char c) : color(clr), row(r), column(c) {}
