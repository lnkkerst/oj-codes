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

#define int long long

void solve() {
  int n;
  cin >> n;
  using pii = pair<int, int>;
  vector<vector<pii>> a(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i].emplace_back(x, y);
  }
  auto pow2 = [&](int x) {
    return x * x;
  };
  auto dis2 = [&](pii a, pii b) {
    return pow2(a.first - b.first) + pow2(a.second - b.second);
  };
  for (int qwq = 1; qwq <= n - 1; ++qwq) {
    pii mi = {0, 1};
    int midis = 1e12;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = i + 1; j < a.size(); ++j) {
        int tot = 0;
        for (auto x : a[i]) {
          for (auto y : a[j]) {
            tot += dis2(x, y);
          }
        }
        int ldis = midis * a[i].size() * a[j].size();
        int rdis = tot * a[mi.first].size() * a[mi.second].size();
        if (ldis == rdis) {
          if (min(mi.first, mi.second) == min(i, j)) {
            if (max(mi.first, mi.second) > max(i, j)) {
              mi = {i, j};
              midis = tot;
            }
          } else if (min(mi.first, mi.second) > min(i, j)) {
            mi = {i, j};
            midis = tot;
          }
        } else if (ldis > rdis) {
          mi = {i, j};
          midis = tot;
        }
      }
    }
    vector<pii> nc = a[mi.first];
    for (auto i : a[mi.second]) {
      nc.emplace_back(i);
    }
    decltype(a) na;
    for (int i = 0; i < a.size(); ++i) {
      if (i == mi.first || i == mi.second) {
        continue;
      }
      na.emplace_back(a[i]);
    }
    na.emplace_back(nc);
    a = na;
    cout << nc.size() << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
