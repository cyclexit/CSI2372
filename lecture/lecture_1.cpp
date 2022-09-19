/*
 * author: cyclexit
 * start from: 2022-09-07 15:08
 */
#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;

i32 main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // s1: pattern; s: text
  string s1, s2;
  // NOTE: use getline() if white spaces are included in the given string
  //       cin is space sensitive
  cin >> s1 >> s2;
  vector<i32> res;

  for (int j = 0; j < s2.size(); ++j) {
    bool flag = true;
    for (int i = 0; i < s1.size(); ++i) {
      if (j + i >= s2.size()) {
        flag = false;
        break;
      }
      if (s2[j + i] != s1[i]) {
        flag = false;
        break;
      }
    }
    if (flag) res.push_back(j);
  }

  string s1_rev = s1;
  reverse(s1_rev.begin(), s1_rev.end());
  for (int j = 0; j < s2.size(); ++j) {
    bool flag = true;
    for (int i = 0; i < s1_rev.size(); ++i) {
      if (j + i >= s2.size()) {
        flag = false;
        break;
      }
      if (s2[j + i] != s1_rev[i]) {
        flag = false;
        break;
      }
    }
    if (flag) res.push_back(-(j + s1_rev.size() - 1));
  }

  for (i32 idx : res) {
    cout << idx << " ";
  }
  cout << '\n';

  return 0;
}

/*
Sample Input:
abc
extabcjijlcbaiiocba
*/