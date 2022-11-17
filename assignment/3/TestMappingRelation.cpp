// Hongyi Lin 300053082
// Stacy Guo 300157080

#include <bits/stdc++.h>

#include "MappingRelation.cpp"

using namespace std;

int main() {
  // domain and range
  vector<string> domain{"jack", "mike", "jarrod", "eugene", "brad"};
  vector<int> range(10);
  iota(range.begin(), range.end(), 0);

  // test using mr1
  MappingRelation<string, int> mr1;
  for (auto d : domain) {
    mr1.add_to_domain(d);
  }
  for (auto r : range) {
    mr1.add_to_range(r);
  }
  mr1.add_element({domain[0], range[1]});
  mr1.add_element({domain[1], range[0]});
  mr1.add_element({domain[2], range[3]});
  mr1.add_element({domain[3], range[2]});
  cout << mr1 << endl;

  // test using mr2
  MappingRelation<string, int> mr2(set<string>(domain.begin(), domain.end()),
                                   set<int>(range.begin(), range.end()));
  return 0;
}
