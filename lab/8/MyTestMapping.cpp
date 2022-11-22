#include <bits/stdc++.h>

#include "Mapping.cpp"

using namespace std;

int main() {
  Mapping<string, int> m1;

  cout << "after 1st add:" << endl;
  m1.add_item("Mike", 35);
  m1.add_item("Mike", 19);
  m1.add_item("Mike", 60);
  cout << m1 << endl;
  cout << endl;

  cout << "after 2nd add:" << endl;
  m1.add_item("Nadia", 17);
  m1.add_item("Nadia", 80);
  m1.add_item("Nadia", 15);
  cout << m1 << endl;
  cout << endl;

  cout << "after 1st remove (exist):" << endl;
  m1.remove_item("Mike", 19);
  cout << m1 << endl;
  cout << endl;

  cout << "after 1st remove (not-exist):" << endl;
  m1.remove_item("Mike", 19);
  cout << m1 << endl;
  cout << endl;

  cout << "after 1st clear (exist):" << endl;
  m1.clear_item("Nadia");
  cout << m1 << endl;
  cout << endl;

  cout << "after 1st clear (not-exist):" << endl;
  m1.clear_item("Nadia");
  cout << m1 << endl;
  cout << endl;

  cout << "find_item(\"Mike\"):" << endl;
  auto res = m1.find_item("Mike");
  for (auto itr = res.begin(); itr != res.end(); ++itr) {
    if (itr != res.begin()) cout << ", ";
    cout << *itr;
  }
  cout << endl << endl;

  cout << "Copy m1 to m2:" << endl;
  Mapping<string, int> m2(m1);
  m2.add_item("Jack", 10);
  cout << m2 << endl;
  cout << endl;

  cout << "operator[\"Jack\"]" << endl;
  auto res2 = m2["Jack"];
  for (auto itr = res2.begin(); itr != res2.end(); ++itr) {
    if (itr != res2.begin()) cout << ", ";
    cout << *itr;
  }
  cout << endl << endl;

  cout << "Assign m1 to m2:" << endl;
  m2 = m1;
  cout << m2 << endl;

  return 0;
}