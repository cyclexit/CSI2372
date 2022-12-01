#include <numeric>
#include <set>

#include "Poker.h"

Poker::Poker() {
  players_.resize(kDefaultTotalPlayers);
  init_deck();
  shuffle_deck();
}

Poker::Poker(int total_players) {
  players_.resize(total_players);
  init_deck();
  shuffle_deck();
}

bool Poker::add_card(int player_id) {
  if (!is_player_id_valid(player_id)) {
    printf("Error: player_id %d is not valid.\n", player_id);
    return false;
  }
  if (deck_.empty()) {
    printf("Error: deck is empty.\n");
    return false;
  }

  players_[player_id].push_back(deck_.back());
  deck_.pop_back();
  return true;
}

bool Poker::add_to_table() {
  if (deck_.empty()) {
    printf("Error: deck is empty.\n");
    return false;
  }

  table_.push_back(deck_.back());
  deck_.pop_back();
  return true;
}

bool Poker::IsStraightFlush(const std::vector<PokerCard>& hand) {
  return IsStraight(hand) && IsFlush(hand);
}

bool Poker::IsFourofaKind(const std::vector<PokerCard>& hand) {
  if (!is_hand_legal(hand)) return false;

  std::map<std::string, int> rank_counter;
  for (const auto& card : hand) {
    ++rank_counter[card.rank];
  }
  for (auto p : rank_counter) {
    if (p.second == 4) return true;
  }
  return false;
}

bool Poker::IsFullHouse(const std::vector<PokerCard>& hand) {
  if (!is_hand_legal(hand)) return false;

  std::map<std::string, int> rank_counter;
  for (const auto& card : hand) {
    ++rank_counter[card.rank];
  }
  if (rank_counter.size() != 2) return false;
  for (auto p : rank_counter) {
    if (p.second == 2) return true;
  }
  return false;
}

bool Poker::IsFlush(const std::vector<PokerCard>& hand) {
  if (!is_hand_legal(hand)) return false;

  std::set<std::string> suit_set;
  for (const auto& card : hand) {
    suit_set.insert(card.suit);
  }
  return suit_set.size() == 1;
}

bool Poker::IsStraight(const std::vector<PokerCard>& hand) {
  if (!is_hand_legal(hand)) return false;

  std::set<int> rank_set;
  for (const auto& card : hand) {
    rank_set.insert(kPokerCardRanks.at(card.rank));
  }
  if (rank_set.size() != kHandSize) return false;

  // special check for royal flush
  std::vector<int> ranks(rank_set.begin(), rank_set.end()); // already sorted
  int sum = std::accumulate(ranks.begin(), ranks.end(), 0);
  if (sum == 47 && ranks[0] == 1 && ranks[kHandSize - 1] == 13) return true;

  // normal check for other flushes
  for (int i = 1; i < ranks.size(); ++i) {
    if (ranks[i] != ranks[i - 1] + 1) return false;
  }
  return true;
}

bool Poker::IsThreeofaKind(const std::vector<PokerCard>& hand) {
  if (!is_hand_legal(hand)) return false;

  std::map<std::string, int> rank_counter;
  for (const auto& card : hand) {
    ++rank_counter[card.rank];
  }
  if (rank_counter.size() != 3) return false;
  for (auto p : rank_counter) {
    if (p.second == 3) return true;
  }
  return false;
}

bool Poker::IsTwoPairs(const std::vector<PokerCard>& hand) {
  if (!is_hand_legal(hand)) return false;

  std::map<std::string, int> rank_counter;
  for (const auto& card : hand) {
    ++rank_counter[card.rank];
  }
  int pair_cnt = 0;
  for (auto p : rank_counter) {
    if (p.second == 2) ++pair_cnt;
  }
  return pair_cnt == 2;
}

bool Poker::IsOnePair(const std::vector<PokerCard>& hand) {
  if (!is_hand_legal(hand)) return false;

  std::map<std::string, int> rank_counter;
  for (const auto& card : hand) {
    ++rank_counter[card.rank];
  }
  int pair_cnt = 0;
  for (auto p : rank_counter) {
    if (p.second == 2) ++pair_cnt;
  }
  return pair_cnt == 1;
}
