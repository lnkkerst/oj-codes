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

struct Tree {
#define ls (u << 1)
#define rs (u << 1 | 1)

private:
  int n;
  vector<int> a, ma;

  void pushdown(int u, int len) {
    a[ls] += a[u];
    a[rs] += a[u];
    ma[ls] += a[u];
    ma[rs] += a[u];
    a[u] = 0;
  }

  void pushup(int u) {
    ma[u] = max(ma[ls], ma[rs]);
  }

  void add(int l, int r, int L, int R, int x, int u) {
    int len = r - l + 1;
    if (l >= L && r <= R) {
      a[u] += x;
      ma[u] += x;
      return;
    }
    if (a[u]) {
      pushdown(u, len);
    }
    int mid = ((r - l) >> 1) + l;
    if (L <= mid) {
      add(l, mid, L, R, x, ls);
    }
    if (R > mid) {
      add(mid + 1, r, L, R, x, rs);
    }
    pushup(u);
  }

  int query(int l, int r, int L, int R, int u) {
    int len = r - l + 1;
    if (l >= L && r <= R) {
      return ma[u];
    }
    if (a[u]) {
      pushdown(u, len);
    }
    int mid = ((r - l) >> 1) + l, res = 0;
    if (L <= mid) {
      res = max(res, query(l, mid, L, R, ls));
    }
    if (R > mid) {
      res = max(res, query(mid + 1, r, L, R, rs));
    }
    return res;
  }

public:
  Tree(int _n): n(_n), a((_n + 2) * 4), ma((_n + 2) * 4) {}

  void add(int l, int r, int x) {
    return add(1, n, l, r, x, 1);
  }

  int query(int l, int r) {
    return query(1, n, l, r, 1);
  }

#undef ls
#undef rs
};

void solve() {
  int n;
  cin >> n;
  vector<int> fa(n + 1);
  vector<int> a(n + 1);
  vector<vector<int>> e(n + 1);
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    fa[i] = p;
    e[p].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> dfn(n + 1);
  vector<int> sz(n + 1);
  vector<int> ca(n + 1);
  vector<int> lc(n + 1);
  vector<vector<int>> cs(n + 1);
  int cid = 0;
  function<void(int)> dfs1 = [&](int u) {
    sz[u] = 1;
    dfn[u] = ++cid;
    ca[u] = lc[a[u]];
    lc[a[u]] = u;
    cs[ca[u]].emplace_back(u);
    for (auto v : e[u]) {
      dfs1(v);
      sz[u] += sz[v];
    }
    lc[a[u]] = ca[u];
  };
  dfs1(1);
  Tree tr(n + 10);
  int ans = 0;
  function<void(int)> dfs = [&](int u) {
    for (auto v : e[u]) {
      dfs(v);
    }
    tr.add(dfn[u], dfn[u] + sz[u] - 1, 1);
    for (auto v : cs[u]) {
      tr.add(dfn[v], dfn[v] + sz[v] - 1, -1);
    }

    int mx1 = 1, mx2 = 1;
    for (auto v : e[u]) {
      mx1 = max(mx1, tr.query(dfn[v], dfn[v] + sz[v] - 1));
      if (mx1 > mx2) {
        swap(mx1, mx2);
      }
    }
    ans = max(ans, (mx1) * (mx2));
  };
  dfs(1);
  cout << ans << endl;
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
