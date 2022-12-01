#include <bits/stdc++.h>

#include "TexasHoldem.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    if (i > 0) out << ", ";
    out << vec[i];
  }
  return out;
}

int main() {
  TexasHoldem t1;
  t1.deal();
  cout << t1 << endl;
  cout << t1.hands() << endl;
  return 0;
}