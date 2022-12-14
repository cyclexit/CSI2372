#include <bits/stdc++.h>

#include "BigInteger.h"

using namespace std;

int main() {
  // Test BigInteger cin
  // BigInteger b0;
  // cin >> b0;
  // cout << b0 << endl;
  // cout << --b0 << endl;

  // simple test
  BigInteger b1(99, 10);
  cout << b1 << endl;
  b1 /= -9;
  cout << b1 << endl;
  // cout << (22 / b1) << endl;
  b1.add_digit(0);
  b1.remove_digit();
  cout << "b1 = " << b1 << "(10)" << endl;
  // int, BigInteger
  cout << (10 + b1) << endl;
  cout << (10 - b1) << endl;
  BigInteger b1_1(-2, 16);
  cout << "b1_1 = " << b1_1 << "(16)" << endl;
  cout << b1 / b1_1 << endl;
  cout << b1 % b1_1 << endl;
 
  // stress test with add_digit
  for (int i = 0; i < 100; ++i) {
    b1.add_digit(i % 10);
  }
  cout << b1 << endl;

  // arithmetic test with primitive int
  b1 += 123;
  cout << b1 << endl;
  // int, BigInteger
  cout << (10 + b1) << endl;
  cout << (10 - b1) << endl;

  b1 *= -2;
  cout << b1 << endl;
  cout << (b1 * -1) << endl;
  cout << (b1 - 1) << endl;

  b1 += 1000;
  cout << b1 << endl;

  // comparison test
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

  b2 = -1000;
  cout << b2 << " " << b3 << endl;
  printf("(b2 < b3) = %d\n", (b2 < b3));
  printf("(b2 <= b3) = %d\n", (b2 <= b3));
  printf("(b2 > b3) = %d\n", (b2 > b3));
  printf("(b2 >= b3) = %d\n", (b2 >= b3));
  printf("(b2 == b3) = %d\n", (b2 == b3));
  printf("(b2 != b3) = %d\n", (b2 != b3));

  printf("flip the side of b2 and b3\n");
  cout << b2 << " " << b3 << endl;
  printf("(b3 < b2) = %d\n", (b3 < b2));
  printf("(b3 <= b2) = %d\n", (b3 <= b2));
  printf("(b3 > b2) = %d\n", (b3 > b2));
  printf("(b3 >= b2) = %d\n", (b3 >= b2));
  printf("(b3 == b2) = %d\n", (b3 == b2));
  printf("(b3 != b2) = %d\n", (b3 != b2));

  b2 = -1000;
  b3 = -100;
  cout << b2 << " " << b3 << endl;
  printf("(b2 < b3) = %d\n", (b2 < b3));
  printf("(b2 <= b3) = %d\n", (b2 <= b3));
  printf("(b2 > b3) = %d\n", (b2 > b3));
  printf("(b2 >= b3) = %d\n", (b2 >= b3));
  printf("(b2 == b3) = %d\n", (b2 == b3));
  printf("(b2 != b3) = %d\n", (b2 != b3));

  // comparison test different base
  b2 = BigInteger(100, 10);
  b3 = BigInteger(100, 16);
  cout << b2 << "(10) " << b3 << "(16)" << endl;
  printf("(b2 < b3) = %d\n", (b2 < b3));
  printf("(b2 <= b3) = %d\n", (b2 <= b3));
  printf("(b2 > b3) = %d\n", (b2 > b3));
  printf("(b2 >= b3) = %d\n", (b2 >= b3));
  printf("(b2 == b3) = %d\n", (b2 == b3));
  printf("(b2 != b3) = %d\n", (b2 != b3));

  b3 = 472;
  cout << b2 << "(10) " << b3 << "(16)" << endl;
  printf("(b2 < b3) = %d\n", (b2 < b3));
  printf("(b2 <= b3) = %d\n", (b2 <= b3));
  printf("(b2 > b3) = %d\n", (b2 > b3));
  printf("(b2 >= b3) = %d\n", (b2 >= b3));
  printf("(b2 == b3) = %d\n", (b2 == b3));
  printf("(b2 != b3) = %d\n", (b2 != b3));

  // arithmetic test with different signs and bases
  b2 -= b3;
  cout << b2 << endl;
  cout << ++b2 << endl;
  cout << --b3 << endl;

  cout << "b2 = " << b2 << "(100)" << endl;
  cout << "b3 = " << b3 << "(100)" << endl;

  cout << b2 / b3 << endl;
  cout << b2 % b3 << endl;

  cout << (b2 /= b3) << endl;
  cout << b2 % b3 << endl;

  cout << --b2 << endl;

  return 0;
}