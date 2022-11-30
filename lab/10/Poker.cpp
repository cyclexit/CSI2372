#include <cstdio>

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
