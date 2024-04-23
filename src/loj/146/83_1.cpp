/**
 * @file
 * @brief
 * 树状数组 + 倍增 LCA 会 TLE 一个点，目测是 LCA 的锅
 */

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

using i32 = int;
#define int long long
#define endl '\n'

struct Fenwick {
  int n;
  vector<int> a;

  static int lowbit(int x) {
    return x & -x;
  }

  Fenwick(int _n) {
    n = _n;
    a = vector<int>(n + 10);
  }

  int query(int r) {
    int res = 0;
    while (r > 0) {
      res += a[r];
      r -= lowbit(r);
    }
    return res;
  }

  int query(int l, int r) {
    return query(r) - query(l - 1);
  }

  void add(int pos, int val) {
    if (pos == 0) {
      return;
    }
    while (pos <= n) {
      a[pos] += val;
      pos += lowbit(pos);
    }
  }
};

void solve() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> a(n + 1);
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  int top = 0;
  vector<int> dfn(n + 1);
  vector<int> sz(n + 1);
  function<void(int, int)> dfs = [&](int u, int pre) {
    sz[u] = 1;
    dfn[u] = ++top;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      sz[u] += sz[v];
    }
  };
  dfs(r, 0);
  vector<vector<i32>> fa(n + 1, vector<i32>(23));
  vector<i32> dep(n + 1);
  function<void(int, int)> dfs_lca = [&](int u, int pre) {
    dep[u] = dep[pre] + 1;
    fa[u][0] = pre;
    for (int i = 1; i <= 20; ++i) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs_lca(v, u);
    }
  };
  dfs_lca(r, 0);
  vector<int> l2(n + 1);
  for (int i = 1; i <= n; ++i) {
    l2[i] = l2[i - 1] + ((1 << l2[i - 1]) == i);
  }
  for (int i = 1; i <= n; ++i) {
    --l2[i];
  }
  auto lca = [&](int u, int v) -> i32 {
    if (dep[u] < dep[v]) {
      swap(u, v);
    }
    while (dep[u] > dep[v]) {
      u = fa[u][l2[dep[u] - dep[v]]];
    }
    if (u == v) {
      return u;
    }
    for (int k = l2[dep[u]]; k >= 0; --k) {
      if (fa[u][k] != fa[v][k]) {
        u = fa[u][k];
        v = fa[v][k];
      }
    }
    return fa[u][0];
  };
  Fenwick t1(n), t2(n);
  auto add = [&](int u, int v, int x) {
    int f = lca(u, v);
    t1.add(dfn[u], x);
    t1.add(dfn[v], x);
    t1.add(dfn[f], -x);
    t1.add(dfn[fa[f][0]], -x);
    t2.add(dfn[u], x * dep[u]);
    t2.add(dfn[v], x * dep[v]);
    t2.add(dfn[f], -x * dep[f]);
    t2.add(dfn[fa[f][0]], -x * dep[fa[f][0]]);
  };
  for (int i = 1; i <= n; ++i) {
    add(i, i, a[i]);
  }
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, v, x;
      cin >> u >> v >> x;
      add(u, v, x);
    } else if (op == 2) {
      int u;
      cin >> u;
      cout << t1.query(dfn[u], dfn[u] + sz[u] - 1) << endl;
    } else {
      int u;
      cin >> u;
      int ans = 0;
      ans += t2.query(dfn[u], dfn[u] + sz[u] - 1);
      ans -= t1.query(dfn[u], dfn[u] + sz[u] - 1) * (dep[u] - 1);
      cout << ans << endl;
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
