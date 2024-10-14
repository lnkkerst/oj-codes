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

constexpr int MAX_BITSET_SIZE = 1e6 + 100;

using ll = long long;

template <int len = 1>
int knapsack01(const vector<int> &a, int target) {
  if (target >= len) {
    return knapsack01<min(len * 2, MAX_BITSET_SIZE)>(a, target);
  }
  bitset<len> dp;
  dp[0] = 1;
  for (auto x : a) {
    dp |= dp << x;
  }
  for (int i = target; i >= 0; --i) {
    if (dp[i]) {
      return i;
    }
  }
  return 0;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    e[p].emplace_back(i);
  }
  vector<int> sz(n + 1), vis(n + 1);
  ll ans = 0;
  function<void(int, int)> dfs = [&](int u, int pre) {
    if (vis[u]) {
      return;
    }
    sz[u] = 1;
    vis[u] = true;
    map<int, int> b;
    int tot = 0;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      sz[u] += sz[v];
      ++b[sz[v]];
      tot += sz[v];
    }
    if (b.empty()) {
      return;
    }
    int target = tot / 2;
    if (b.rbegin()->first >= target) {
      ans += (ll)b.rbegin()->first * (tot - b.rbegin()->first);
      return;
    }
    vector<int> a;
    for (auto [x, cnt] : b) {
      int base = 1;
      int k = cnt;
      while (k > base) {
        k -= base;
        a.emplace_back(x * base);
        base *= 2;
      }
      a.emplace_back(x * k);
    }
    int mx = knapsack01(a, target);
    ans += (ll)mx * (tot - mx);
  };
  dfs(1, 0);
  cout << ans << endl;
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
