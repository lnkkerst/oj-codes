#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n + 1);
  vector<int> sz(n + 1);
  vector<int> a(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(m + 2));
  for (int i = 1; i <= n; ++i) {
    int fa;
    cin >> fa >> a[i];
    e[fa].emplace_back(i);
  }
  function<void(int)> dfs = [&](int u) {
    sz[u] = 1;
    dp[u][1] = a[u];
    for (auto v : e[u]) {
      dfs(v);
      for (int i = m + 1; i > 0; --i) {
        for (int j = 0; j <= sz[v] && i + j <= m + 1; ++j) {
          dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j]);
        }
      }
      sz[u] += sz[v];
    }
  };
  dfs(0);
  cout << dp[0][m + 1] << endl;
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
