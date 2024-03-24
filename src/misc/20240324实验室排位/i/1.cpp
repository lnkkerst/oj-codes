#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    e[i].emplace_back(p);
    e[p].emplace_back(i);
  }

  int ans = 0;

  function<int(int, int)> dfs = [&](int u, int pre) -> int {
    int sz = 0;
    deque<int> a;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      int vsz = dfs(v, u);
      a.emplace_back(vsz);
      sz += vsz;
    }
    int n = a.size();
    int mx = sz / 2;
    deque<int> dp(mx + 10);
    for (int i = 0; i < n; ++i) {
      for (int j = mx; j >= a[i]; --j) {
        dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
      }
    }
    int l = dp[mx];
    int r = sz - l;
    ans += l * r;
    return sz + 1;
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

  return 0;
}
