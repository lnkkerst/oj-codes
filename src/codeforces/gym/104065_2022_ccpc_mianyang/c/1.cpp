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
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);

  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vector<int> h(n + 1);
  function<void(int, int)> dfs = [&](int u, int pre) {
    h[u] = 1;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      h[u] = max(h[u], h[v] + 1);
    }
  };
  dfs(1, 0);
  int ans = 0;
  for (auto u : e[1]) {
    ans += h[u];
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
