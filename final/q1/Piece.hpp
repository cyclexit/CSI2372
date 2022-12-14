#ifndef FINAL_PIECE_H_
#define FINAL_PIECE_H_

#include <string>
#include <vector>

using namespace std;

class Piece {
 public:
  static constexpr int kMinRow = 0;
  static constexpr int kMaxRow = 8;
  static constexpr char kMinColumn = 'a';
  static constexpr char kMaxColumn = 'h';

  Piece() = default;
  ~Piece() = default;

  virtual bool move(int r, char c) = 0;
};

#endif // FINAL_PIECE_H_