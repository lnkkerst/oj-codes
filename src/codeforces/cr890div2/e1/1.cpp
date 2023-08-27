#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int> sz(n + 1), vis(n + 1), fa(n + 1);
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    e[i].emplace_back(x);
    e[x].emplace_back(i);
  }
  int ans = 0;
  function<void(int, int)> dfs = [&](int u, int p) {
    if (vis[u]) {
      return;
    }
    vector<int> a;
    vis[u] = true;
    sz[u] = 1;
    for (auto v : e[u]) {
      if (!vis[v] && v != p) {
        dfs(v, u);
        sz[u] += sz[v];
        a.emplace_back(sz[v]);
      }
    }
    int su = accumulate(a.begin(), a.end(), 0);
    int tar = su / 2;
    vector<int> dp(tar + 1);
    for (int i = 1; i <= a.size(); ++i) {
      for (int j = tar; j >= a[i - 1]; --j) {
        dp[j] = max(dp[j], dp[j - a[i - 1]] + a[i - 1]);
      }
    }
    ans += dp[tar] * (su - dp[tar]);
  };
  dfs(1, -1);
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
