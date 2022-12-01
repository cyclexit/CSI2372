#include <bits/stdc++.h>

#include "Poker.h"

using namespace std;

int main() {
  // IsStraightFlush
  vector<PokerCard> h1 {
    {"T", "S"},
    {"J", "S"},
    {"Q", "S"},
    {"K", "S"},
    {"A", "S"}
  };
  if (Poker::IsStraightFlush(h1)) {
    cout << "Test IsStraightFlush true... Passed" << endl;
  } else {
    cout << "Test IsStraightFlush true... Failed" << endl;
  }
  h1 = {
    {"2", "S"},
    {"3", "S"},
    {"4", "S"},
    {"5", "S"},
    {"A", "S"}
  };
  if (Poker::IsStraightFlush(h1)) {
    cout << "Test IsStraightFlush true... Passed" << endl;
  } else {
    cout << "Test IsStraightFlush true... Failed" << endl;
  }
  h1 = {
    {"8", "S"},
    {"9", "S"},
    {"T", "S"},
    {"2", "S"},
    {"3", "S"}
  };
  if (!Poker::IsStraightFlush(h1)) {
    cout << "Test IsStraightFlush false... Passed" << endl;
  } else {
    cout << "Test IsStraightFlush false... Failed" << endl;
  }

  // IsFourofaKind
  return 0;
}