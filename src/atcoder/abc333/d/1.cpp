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
  vector<int> sz(n + 1);
  function<void(int, int)> dfs = [&](int u, int pre) {
    sz[u] = 1;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      sz[u] += sz[v];
    }
  };
  dfs(1, 0);
  if (e[1].size() <= 1) {
    cout << 1 << endl;
    return;
  }
  int ma = 0;
  for (auto u : e[1]) {
    ma = max(ma, sz[u]);
  }
  cout << n - ma << endl;
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
