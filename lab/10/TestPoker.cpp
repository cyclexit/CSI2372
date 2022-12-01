#include <bits/stdc++.h>

#include "Poker.h"

using namespace std;

int main() {
  vector<PokerCard> h1 {
    {"T", "S"},
    {"J", "S"},
    {"Q", "S"},
    {"K", "S"},
    {"A", "S"}
  };
  if (Poker::IsStraightFlush(h1)) {
    cout << "Test IsStraightFlush... Passed" << endl;
  } else {
    cout << "Test IsStraightFlush... Failed" << endl;
  }
  return 0;
}