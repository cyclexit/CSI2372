#include "TexasHoldem.h"

TexasHoldem::TexasHoldem() : Poker() {}

TexasHoldem::TexasHoldem(int total_players) : Poker(total_players) {}

void TexasHoldem::deal() {
  // give 2 cards to each player
  for (int i = 0; i < players_.size(); ++i) {
    for (int j = 0; j < kPlayHandSize; ++j) {
      add_card(i);
    }
  }
  // add 5 cards to the table
  for (int i = 0; i < kTableSize; ++i) {
    add_to_table();
  }
}

std::vector<std::string> TexasHoldem::hands() {
  return {};
}
