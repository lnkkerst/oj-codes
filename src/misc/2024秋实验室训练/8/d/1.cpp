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

constexpr int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> f(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i % MOD;
  }
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  sort(a.begin(), a.end());
  auto calc = [&](map<int, int> &mp) {
    int res = 1;
    for (auto [x, c] : mp) {
      res *= f[c];
      res %= MOD;
    }
    return res;
  };
  map<int, int> tmp1, tmp2;
  for (auto [x, y] : a) {
    tmp1[x]++;
    tmp2[y]++;
  }
  int ans = 1;
  int last = -1;
  int lastmx = 0;
  map<int, int> cur;
  for (auto [x, y] : a) {
    if (x == last) {
      ++cur[y];
    } else {
      if (!cur.empty() && cur.begin()->first < lastmx) {
        ans = 0;
      }
      if (!cur.empty()) {
        lastmx = cur.rbegin()->first;
      }
      ans *= calc(cur);
      ans %= MOD;
      cur.clear();
      ++cur[y];
    }
    last = x;
  }

  if (!cur.empty() && cur.begin()->first < lastmx) {
    ans = 0;
  }
  ans *= calc(cur);
  ans %= MOD;
  ans = ((calc(tmp1) + calc(tmp2) - ans) % MOD + MOD) % MOD;
  ans = ((f[n] - ans) % MOD + MOD) % MOD;

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
