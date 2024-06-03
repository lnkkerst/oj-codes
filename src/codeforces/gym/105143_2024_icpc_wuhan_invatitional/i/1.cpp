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
  string s;
  cin >> s;
  vector<string> a;
  string cs = "";
  for (auto c : s) {
    if (cs.empty()) {
      cs += c;
      continue;
    }
    if (c != cs.front()) {
      a.emplace_back(cs);
      cs = "";
    }
    cs += c;
  }
  if (!cs.empty()) {
    a.emplace_back(cs);
  }
  int ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (i && a[i].front() == '0') {
      ++ans;
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
