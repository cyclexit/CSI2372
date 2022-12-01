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
  vector<PokerCard> h2 {
    {"9", "S"},
    {"9", "C"},
    {"9", "D"},
    {"9", "H"},
    {"A", "S"}
  };
  if (Poker::IsFourofaKind(h2)) {
    cout << "Test IsFourofaKind true... Passed" << endl;
  } else {
    cout << "Test IsFourofaKind true... Failed" << endl;
  }
  h2 = {
    {"9", "S"},
    {"8", "C"},
    {"9", "D"},
    {"9", "H"},
    {"A", "S"}
  };
  if (!Poker::IsFourofaKind(h2)) {
    cout << "Test IsFourofaKind false... Passed" << endl;
  } else {
    cout << "Test IsFourofaKind false... Failed" << endl;
  }

  // IsFullHouse
  vector<PokerCard> h3 {
    {"9", "S"},
    {"9", "C"},
    {"9", "D"},
    {"A", "H"},
    {"A", "S"}
  };
  if (Poker::IsFullHouse(h3)) {
    cout << "Test IsFullHouse true... Passed" << endl;
  } else {
    cout << "Test IsFullHouse true... Failed" << endl;
  }
  h3 = {
    {"9", "S"},
    {"9", "C"},
    {"9", "D"},
    {"9", "H"},
    {"A", "S"}
  };
  if (!Poker::IsFullHouse(h3)) {
    cout << "Test IsFullHouse false... Passed" << endl;
  } else {
    cout << "Test IsFullHouse false... Failed" << endl;
  }
  return 0;
}