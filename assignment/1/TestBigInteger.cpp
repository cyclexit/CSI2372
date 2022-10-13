#include <bits/stdc++.h>

#include "BigInteger.h"

using namespace std;

int main() {
  BigInteger b1(99, 10);
  cout << b1 << endl;

  b1.add_digit(0);
  b1.remove_digit();
  cout << b1 << endl;

  b1 += 123;
  cout << b1 << endl;

  b1 *= -2;
  cout << b1 << endl;
  cout << (b1 * -1) << endl;

  BigInteger b2(99, 10), b3(1000, 10);
  cout << b2 << " " << b3 << endl;
  printf("(b2 < b3) = %d\n", (b2 < b3));
  printf("(b2 <= b3) = %d\n", (b2 <= b3));
  printf("(b2 > b3) = %d\n", (b2 > b3));
  printf("(b2 >= b3) = %d\n", (b2 >= b3));
  printf("(b2 == b3) = %d\n", (b2 == b3));
  printf("(b2 != b3) = %d\n", (b2 != b3));

  b2 = 1000;
  cout << b2 << " " << b3 << endl;
  printf("(b2 < b3) = %d\n", (b2 < b3));
  printf("(b2 <= b3) = %d\n", (b2 <= b3));
  printf("(b2 > b3) = %d\n", (b2 > b3));
  printf("(b2 >= b3) = %d\n", (b2 >= b3));
  printf("(b2 == b3) = %d\n", (b2 == b3));
  printf("(b2 != b3) = %d\n", (b2 != b3));

  b2 = 9999;
  cout << b2 << " " << b3 << endl;
  printf("(b2 < b3) = %d\n", (b2 < b3));
  printf("(b2 <= b3) = %d\n", (b2 <= b3));
  printf("(b2 > b3) = %d\n", (b2 > b3));
  printf("(b2 >= b3) = %d\n", (b2 >= b3));
  printf("(b2 == b3) = %d\n", (b2 == b3));
  printf("(b2 != b3) = %d\n", (b2 != b3));

  return 0;
}