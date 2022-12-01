#include "TexasHoldem.h"

TexasHoldem::TexasHoldem() {
  players_.resize(kDefaultTotalPlayers);
  init_deck();
  shuffle_deck();
}

TexasHoldem::TexasHoldem(int total_players) {
  players_.resize(total_players);
  init_deck();
  shuffle_deck();
}

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
