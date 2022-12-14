#include <utility>

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
  std::vector<std::string> res;

  std::vector<PokerCard> seven_cards(table_);
  assert(seven_cards.size() == kTableSize);
  for (const auto& player_hand : players_) {
    for (const auto& card : player_hand) {
      seven_cards.push_back(card);
    }
    assert(seven_cards.size() == kTableSize + kPlayHandSize);

    std::pair<int, std::string> highest_res(hand_rank_validators.size(), "");
    std::vector<int> selected(seven_cards.size(), 1);
    selected[0] = selected[1] = 0;
    do {
      std::vector<PokerCard> cur;
      for (int i = 0; i < kTableSize + kPlayHandSize; ++i) {
        if (selected[i]) cur.push_back(seven_cards[i]);
      }
      for (int i = 0; i < hand_rank_validators.size(); ++i) {
        if (hand_rank_validators[i].first(cur)) {
          if (i < highest_res.first) {
            highest_res = {i, hand_rank_validators[i].second};
          }
        }
      }
    } while (std::next_permutation(selected.begin(), selected.end()));
    res.push_back(highest_res.second);

    while (seven_cards.size() > kTableSize) {
      seven_cards.pop_back();
    }
    assert(seven_cards.size() == kTableSize);
  }

  return res;
}
