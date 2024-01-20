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
  string s, f;
  cin >> s >> f;
  set<char> bf;
  for (auto c : f) {
    bf.insert(c);
  }
  bool fl = false;
  for (auto c : s) {
    if (bf.find(c) == bf.end()) {
      fl = true;
    }
  }
  cout << (fl ? 0 : 10) << endl;
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
