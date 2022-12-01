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

  friend std::ostream& operator<<(std::ostream& out, const TexasHoldem& texas) {
    out << "Table:" << std::endl;
    for (int i = 0; i < texas.table_.size(); ++i) {
      if (i > 0) out << ", ";
      out << texas.table_[i];
    }
    for (int i = 0; i < texas.players_.size(); ++i) {
      out << "\nPlayer " << i << ":" << std::endl;
      for (const auto& card : texas.players_[i]) {
        if (card != *texas.players_[i].begin()) out << ", ";
        out << card;
      }
    }
    return out;
  }
};

#endif // LAB_10_TEXAS_HOLDEN_H_
