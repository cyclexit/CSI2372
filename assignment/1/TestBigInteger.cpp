#include <bits/stdc++.h>

#include "BigInteger.h"

using namespace std;

int main() {
  BigInteger b1(100, 16);
  cout << b1 << endl;
  b1.add_digit(0);
  b1.remove_digit();
  cout << b1 << endl;
  return 0;
}