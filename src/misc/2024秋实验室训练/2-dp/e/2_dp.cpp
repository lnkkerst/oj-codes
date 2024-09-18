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
  int n, x;
  cin >> n >> x;
  deque<pair<int, int>> a(n);
  set<int> s;
  s.insert(x);
  for (auto &[l, r] : a) {
    cin >> l >> r;
    s.insert(l);
    s.insert(r);
  }
  int top = 0;
  map<int, int> id;
  vector<int> mp(s.size() + 1);
  for (auto x : s) {
    ++top;
    id[x] = top;
    mp[top] = x;
  }
  for (auto &[l, r] : a) {
    l = id[l];
    r = id[r];
  }
  x = id[x];
  a.emplace_front();
  auto calc_cost = [&](pair<int, int> a, int x) {
    auto [l, r] = a;
    l = mp[l];
    r = mp[r];
    x = mp[x];
    if (x > r) {
      return x - r;
    }
    if (x < l) {
      return l - x;
    }
    return 0ll;
  };
  vector<vector<int>> dp(10, vector<int>(top + 1, 1e18));
  dp[0][x] = 0;
  for (int i = 1; i <= n; ++i) {
    vector<int> pm(top + 2);
    vector<int> sm(top + 2);
    pm[0] = 1e18;
    sm[top + 1] = 1e18;
    auto &cur = dp[i & 1];
    auto &prev = dp[!(i & 1)];
    for (int j = 1; j <= top; ++j) {
      pm[j] = min(pm[j - 1], prev[j] - mp[j]);
    }
    for (int j = top; j >= 1; --j) {
      sm[j] = min(sm[j + 1], prev[j] + mp[j]);
    }
    for (int j = 1; j <= top; ++j) {
      cur[j] = calc_cost(a[i], j) + min(sm[j] - mp[j], pm[j] + mp[j]);
    }
  }
  int ans = 1e18;
  for (int i = 1; i <= top; ++i) {
    ans = min(ans, dp[(n & 1)][i]);
  }
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
