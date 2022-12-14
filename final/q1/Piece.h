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

  Piece() = default;
  Piece(int clr, int r, char c);
  ~Piece() = default;

  virtual bool move(int r, char c) = 0;

 private:
  // color: 0 means white and 1 means black.
  int color;
  int cur_row;
  char cur_column;

  static bool in_chessboard(int r, char c) {
    return (kMinRow <= r && r <= kMaxRow)
           && (kMinColumn <= c && c <= kMaxColumn);
  }
};

#endif // FINAL_PIECE_H_
