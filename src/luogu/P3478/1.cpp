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

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int> dep(n + 1), sz(n + 1), dp(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  function<void(int, int)> dfs1 = [&](int u, int fa) {
    dep[u] = dep[fa] + 1;
    sz[u] = 1;
    for (auto v : e[u]) {
      if (v == fa) {
        continue;
      }
      dfs1(v, u);
      sz[u] += sz[v];
    }
  };
  dfs1(1, 0);
  for (int i = 1; i <= n; ++i) {
    dp[1] += dep[i];
  }
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : e[u]) {
      if (v == fa) {
        continue;
      }
      dp[v] = dp[u] - sz[v] + n - sz[v];
      dfs(v, u);
    }
  };
  dfs(1, 0);
  int ma = dp[0];
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i] > ma) {
      ma = dp[i];
      ans = i;
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
