#include <bits/stdc++.h>

#include "TexasHoldem.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    if (i > 0) out << endl;
    out << "Player " << i << ": " << vec[i];
  }
  return out;
}

int main() {
  cout << "Game 1:" << endl;
  TexasHoldem t1;
  t1.deal();
  cout << t1 << endl;
  cout << t1.hands() << endl;
  cout << endl;

  cout << "Game 2:" << endl;
  TexasHoldem t2(7);
  t2.deal();
  cout << t2 << endl;
  cout << t2.hands() << endl;
  return 0;
}