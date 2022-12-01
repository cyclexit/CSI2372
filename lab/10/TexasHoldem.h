#ifndef LAB_10_TEXAS_HOLDEN_H_
#define LAB_10_TEXAS_HOLDEN_H_

#include "Poker.h"

class TexasHoldem : public Poker {
 public:
  static constexpr int kTableSize = 5;
  static constexpr int kPlayHandSize = 2;

  TexasHoldem();
  TexasHoldem(int total_players);

  void deal();
  std::vector<std::string> hands();
};

#endif // LAB_10_TEXAS_HOLDEN_H_
