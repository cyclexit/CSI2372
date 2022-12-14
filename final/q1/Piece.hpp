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
  ~Piece() = default;

  virtual bool move(int r, char c) = 0;
 private:
  static bool in_chessboard(int r, char c) {
    return (kMinRow <= r && r <= kMaxRow)
           && (kMinColumn <= c && c <= kMaxColumn);
  }
};

#endif // FINAL_PIECE_H_