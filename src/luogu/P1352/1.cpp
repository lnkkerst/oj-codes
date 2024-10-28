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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> e(n + 1);
  vector<int> fa(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> v >> u;
    fa[v] = u;
    e[u].emplace_back(v);
  }
  vector<array<int, 2>> dp(n + 1);
  function<void(int)> dfs = [&](int u) {
    dp[u][1] = a[u];
    for (auto v : e[u]) {
      dfs(v);
      dp[u][0] += max(dp[v][1], dp[v][0]);
      dp[u][1] += dp[v][0];
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!fa[i]) {
      dfs(i);
      cout << max(dp[i][0], dp[i][1]) << endl;
      return;
    }
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
