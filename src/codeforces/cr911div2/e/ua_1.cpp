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
#define INT_MAX 1e18

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] *= 2;
  }
  vector<vector<pair<int, int>>> e(n + 1);
  vector<map<int, int>> b(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    if (b[u].find(v) == b[u].end()) {
      b[u][v] = true;
      e[u].emplace_back(v, 0);
    }
  }
  vector<int> vis(n + 1);
  function<void(int, int)> dfs0 = [&](int u, int pre) {
    if (vis[u]) {
      b[pre][u] = false;
      return;
    }
    vis[u] = true;
    for (auto [v, w] : e[u]) {
      dfs0(v, u);
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs0(i, 0);
    }
  }
  for (int i = 1; i <= n; ++i) {
    vector<pair<int, int>> ne;
    for (auto [v, w] : e[i]) {
      if (!b[i][v]) {
        continue;
      }
      ne.emplace_back(v, 0);
    }
    e[i] = ne;
  }
  vector<int> in(n + 1), out(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (auto [v, w] : e[i]) {
      ++in[v];
      ++out[i];
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (auto &[v, w] : e[u]) {
      w = 1e12;
      if (in[u]) {
        w += a[u] / 2;
      }
      if (out[v]) {
        w += a[v] / 2;
      }
    }
  }

  vector<int> dp(n + 1);

  function<int(int)> dfs = [&](int u) {
    if (dp[u] > 0) {
      return dp[u];
    }
    for (auto [v, w] : e[u]) {
      dp[u] = max(dp[u], dfs(v) + w);
    }
    return dp[u];
  };
  int ma = 0;
  for (int i = 1; i <= n; ++i) {
    if (dfs(i) > 0) {
      ma = max(ma, dfs(i));
    }
  }
  cout << (ma / (int)1e12) << ' ' << (ma % (int)1e12) << endl;
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
