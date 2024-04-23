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
  Fenwick tr(n);
  for (int i = 1; i <= n; ++i) {
    tr.add(dfn[i], a[i]);
  }
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, x;
      cin >> u >> x;
      tr.add(dfn[u], x);
    } else {
      int u;
      cin >> u;
      cout << tr.query(dfn[u], dfn[u] + sz[u] - 1) << endl;
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
