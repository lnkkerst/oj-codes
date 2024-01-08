#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  set<int> v{'a', 'e'}, c{'b', 'c', 'd'};
  auto check = [&](char ch) {
    if (c.find(ch) != c.end()) {
      return 'c';
    }
    return 'v';
  };
  for (int i = 0; i < n; ++i) {
    if (check(s[i]) == 'c') {
      t += s[i];
      if (i + 1 >= n) {
        t.pop_back();
        t.pop_back();
        t += s[i];
        continue;
      }
      t += s[i + 1];
      if (i + 3 < n && check(s[i + 3]) == 'c') {
        t += s[i + 2];
        t += '.';
        i += 2;
      } else {
        t += '.';
        ++i;
      }
    }
  }
  if (t.back() == '.') {
    t.pop_back();
  }
  cout << t << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
