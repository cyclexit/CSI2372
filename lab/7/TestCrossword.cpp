#include <bits/stdc++.h>

#include "Crossword.h"

using namespace std;

int main() {
  Crossword cw1;
  cout << cw1 << endl;

  cout << cw1.add_question("What is the capital of Canada?", "Ottawa", 3, 2, true) << endl;
  cout << cw1 << endl;

  cout << cw1.solve(3, 2, "fuck") << endl;

  return 0;
}