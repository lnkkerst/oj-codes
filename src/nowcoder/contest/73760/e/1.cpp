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

constexpr int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vector<vector<int>> dp(n + 1, vector<int>(2));
  function<void(int, int)> dfs = [&](int u, int pre) {
    dp[u] = {1, 1};
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      dp[u][1] *= (dp[v][0] + dp[v][1]) % MOD;
      dp[u][1] %= MOD;
      dp[u][0] *= (dp[v][1]) % MOD;
      dp[u][0] %= MOD;
    }
  };
  dfs(1, 0);
  cout << (dp[1][0] + dp[1][1]) % MOD << endl;
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
