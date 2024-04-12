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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> er(m, vector<int>(3));
  for (auto &x : er) {
    cin >> x[0] >> x[1] >> x[2];
  }
  sort(er.begin(), er.end(),
       [&](const vector<int> &a, const vector<int> &b) -> bool {
         return a[2] > b[2];
       });
  vector<vector<pair<int, int>>> e(n + 1);
  vector<int> fa(n + 1);
  for (int i = 0; i <= n; ++i) {
    fa[i] = i;
  }
  function<int(int)> find = [&](int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
  };
  auto merge = [&](int u, int v) {
    fa[find(u)] = find(v);
  };
  for (auto x : er) {
    int u = x[0];
    int v = x[1];
    int w = x[2];
    if (find(u) == find(v)) {
      continue;
    }
    merge(u, v);
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  vector<int> dep(n + 1);
  vector<vector<int>> f(n + 1, vector<int>(30));
  auto mw = f;
  vector<int> l2(n + 1);
  for (int i = 1; i <= n; ++i) {
    l2[i] = l2[i - 1] + ((1ll << l2[i - 1]) == i);
  }
  function<void(int, int)> dfs_lca = [&](int u, int pre) {
    dep[u] = dep[pre] + 1;
    f[u][0] = pre;
    for (int i = 1; i <= l2[dep[u]]; ++i) {
      f[u][i] = f[f[u][i - 1]][i - 1];
      mw[u][i] = min(mw[u][i - 1], mw[f[u][i - 1]][i - 1]);
    }
    for (auto [v, w] : e[u]) {
      if (v == pre) {
        continue;
      }
      mw[v][0] = w;
      dfs_lca(v, u);
    }
  };
  dfs_lca(1, 0);
  auto calc = [&](int st, int ed) -> int {
    int ans = 1e9;
    int u = st, v = ed;
    if (dep[v] > dep[u]) {
      swap(u, v);
    }
    while (dep[u] > dep[v]) {
      int t = l2[dep[u] - dep[v]] - 1;
      ans = min(ans, mw[u][t]);
      u = f[u][t];
    }
    if (v == u) {
      return ans;
    }
    for (int k = l2[dep[u]] - 1; k >= 0; --k) {
      if (f[u][k] != f[v][k]) {
        ans = min(ans, min(mw[u][k], mw[v][k]));
        u = f[u][k];
        v = f[v][k];
      }
    }
    ans = min(ans, min(mw[u][0], mw[v][0]));
    return ans;
  };
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (find(x) != find(y)) {
      cout << -1 << endl;
    } else {
      cout << calc(x, y) << endl;
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
