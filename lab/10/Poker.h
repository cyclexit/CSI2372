#ifndef LAB_10_POKER_H_
#define LAB_10_POKER_H_

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

static const std::map<std::string, int> kPokerCardRanks {
  {"A", 1},
  {"2", 2},
  {"3", 3},
  {"4", 4},
  {"5", 5},
  {"6", 6},
  {"7", 7},
  {"8", 8},
  {"9", 9},
  {"T", 10},
  {"J", 11},
  {"Q", 12},
  {"K", 13}
};

static const std::vector<std::string> kPokerCardSuits {
  "D", "C", "S", "H"
};

struct PokerCard {
  // [A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K]
  std::string rank;
  // D for diamonds, C for clubs, S for spades, or H for hearts
  std::string suit;

  PokerCard(const std::string& r, const std::string& s) : rank(r), suit(s) {}

  std::string to_string() const {
    return rank + suit;
  }

  friend std::ostream& operator<<(std::ostream& out, const PokerCard& card) {
    out << card.to_string();
    return out;
  }
};

class Poker {
 public:
  Poker();
  Poker(int total_players);

  bool add_card(int player_id);
  bool add_to_table();

  static bool IsStraightFlush(const std::vector<PokerCard>& hand);
  static bool IsFourofaKind(const std::vector<PokerCard>& hand);
  static bool IsFullHouse(const std::vector<PokerCard>& hand);
  static bool IsFlush(const std::vector<PokerCard>& hand);
  static bool IsStraight(const std::vector<PokerCard>& hand);
  static bool IsThreeofaKind(const std::vector<PokerCard>& hand);
  static bool IsTwoPairs(const std::vector<PokerCard>& hand);
  static bool IsOnePair(const std::vector<PokerCard>& hand);

 private:
  static constexpr int kDefaultTotalPlayers = 2;
  static constexpr int kHandSize = 5;

  std::vector<std::vector<PokerCard>> players_;
  std::vector<PokerCard> table_;
  std::vector<PokerCard> deck_;

  bool is_player_id_valid(int player_id) {
    return 0 <= player_id && player_id <= players_.size();
  }

  void init_deck() {
    for (const auto& rank : kPokerCardRanks) {
      for (const auto& suit : kPokerCardSuits) {
        deck_.push_back(PokerCard(rank.first, suit));
      }
    }
    assert(deck_.size() == kPokerCardRanks.size() * kPokerCardSuits.size());
  }

  void shuffle_deck() {
    std::random_shuffle(deck_.begin(), deck_.end());
  }
};

#endif // LAB_10_POKER_H_
