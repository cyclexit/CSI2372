#ifndef FINAL_PIECE_H_
#define FINAL_PIECE_H_

#include <string>
#include <vector>

using namespace std;

class Piece {
 public:
  static constexpr int kMinRow = 1;
  static constexpr int kMaxRow = 8;
  static constexpr char kMinColumn = 'a';
  static constexpr char kMaxColumn = 'h';

  Piece();
  Piece(int clr, int r, char c);
  ~Piece() = default;

  virtual bool is_move_valid(int r, char c) = 0;
  bool move(int r, char c);

 protected:
  // color: 0 means white and 1 means black.
  int color;
  // current position
  int row;
  char column;

  static bool in_chessboard(int r, char c) {
    return (kMinRow <= r && r <= kMaxRow)
           && (kMinColumn <= c && c <= kMaxColumn);
  }
};

#endif // FINAL_PIECE_H_
