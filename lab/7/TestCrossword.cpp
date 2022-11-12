#include <bits/stdc++.h>

#include "Crossword.h"

using namespace std;

int main() {
  Crossword cw1;
  cout << cw1 << endl;

  cout << cw1.add_question("What is the capital of Canada?", "Ottawa", 3, 2, true) << endl;
  cout << cw1 << endl;

  cout << cw1.solve(3, 2, "ottawa") << endl;
  cout << cw1 << endl;

  cout << cw1.add_question("The last name of the current prime minister of Canada?", "Trudeau", 1, 3, false) << endl;
  cout << cw1 << endl;

  cout << cw1.add_question("The only flying mammals?", "Bats", 1, 4, false) << endl;
  cout << cw1 << endl;

  cout << cw1.solve(1, 4, "bats") << endl;
  cout << cw1 << endl;

  return 0;
}
