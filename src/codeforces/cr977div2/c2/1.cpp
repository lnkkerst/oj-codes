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

// min
struct Tree {
#define ls (u << 1)
#define rs (u << 1 | 1)

private:
  int n;
  vector<int> a, mi;

  void pushdown(int u, int len) {
    a[ls] += a[u];
    a[rs] += a[u];
    mi[ls] += a[u];
    mi[rs] += a[u];
    a[u] = 0;
  }

  void pushup(int u) {
    mi[u] = min(mi[ls], mi[rs]);
  }

  void add(int l, int r, int L, int R, int x, int u) {
    int len = r - l + 1;
    if (l >= L && r <= R) {
      a[u] += x;
      mi[u] += x;
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
      return mi[u];
    }
    if (a[u]) {
      pushdown(u, len);
    }
    int mid = ((r - l) >> 1) + l, res = 1e12;
    if (L <= mid) {
      res = min(res, query(l, mid, L, R, ls));
    }
    if (R > mid) {
      res = min(res, query(mid + 1, r, L, R, rs));
    }
    return res;
  }

public:
  Tree(int _n): n(_n), a((_n + 2) * 4), mi((_n + 2) * 4) {}

  void add(int l, int r, int x) {
    return add(1, n, l, r, x, 1);
  }

  void set(int k, int x) {
    add(k, k, -query(k, k));
    add(k, k, x);
  }

  int query(int l, int r) {
    return query(1, n, l, r, 1);
  }

#undef ls
#undef rs
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n + 1);
  vector<int> b(m + 1);
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  vector<int> vis(n + 1);
  int offset = 0;
  Tree tr(m + 10);
  for (int i = 1; i <= m; ++i) {
    if (vis[b[i]]) {
      ++offset;
    }
    vis[b[i]] = 1;
    tr.add(i, i, i - pos[b[i]] - offset);
  }

  vector<set<int>> bk(n + 1);
  for (int i = 1; i <= m; ++i) {
    bk[b[i]].insert(i);
  }

  cout << ((tr.query(1, m) >= 0) ? "YA" : "TIDAK") << endl;

  while (q--) {
    int s, t;
    cin >> s >> t;

    tr.add(s, s, pos[b[s]]);
    tr.add(s, s, -pos[t]);

    if (s == *bk[b[s]].begin()) {
      if (bk[b[s]].size() >= 2) {
        tr.add(*++bk[b[s]].begin(), m, 1);
      }
    } else {
      tr.add(s, m, 1);
    }

    bk[b[s]].erase(s);

    if (bk[t].empty() || *bk[t].begin() > s) {
      if (!bk[t].empty()) {
        tr.add(*bk[t].begin(), m, -1);
      }
    } else {
      tr.add(s, m, -1);
    }

    bk[t].insert(s);

    b[s] = t;

    cout << ((tr.query(1, m) >= 0) ? "YA" : "TIDAK") << endl;
  }
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
