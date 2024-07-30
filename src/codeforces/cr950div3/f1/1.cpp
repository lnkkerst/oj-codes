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

struct Treap {
  vector<int> ls, rs, a, p, sz, cnt;
  int tot = 0, rt = 0;
  int notFound;

  Treap(int _n, int _notFound = (1u << 31) - 1) : notFound(_notFound) {
    ls = rs = a = p = sz = cnt = vector<int>(_n + 10);
  }

  void pushup(int u) {
    sz[u] = sz[ls[u]] + sz[rs[u]] + cnt[u];
  }

  void rotateL(int &u) {
    int t = rs[u];
    rs[u] = ls[t];
    ls[t] = u;
    sz[t] = sz[u];
    pushup(u);
    u = t;
  }

  void rotateR(int &u) {
    int t = ls[u];
    ls[u] = rs[t];
    rs[t] = u;
    sz[t] = sz[u];
    pushup(u);
    u = t;
  }

  int newNode(int x) {
    int u = ++tot;
    sz[u] = 1;
    cnt[u] = 1;
    a[u] = x;
    p[u] = rand();
    return u;
  }

  void insert(int &u, int x) {
    if (!u) {
      u = newNode(x);
      return;
    }
    ++sz[u];
    if (a[u] == x) {
      ++cnt[u];
    } else if (a[u] < x) {
      insert(rs[u], x);
      if (p[rs[u]] < p[u]) {
        rotateL(u);
      }
    } else {
      insert(ls[u], x);
      if (p[ls[u]] < p[u]) {
        rotateR(u);
      }
    }
  }

  void insert(int x) {
    return insert(rt, x);
  }

  bool remove(int &u, int x) {
    if (!u) {
      return false;
    }
    if (a[u] == x) {
      if (cnt[u] > 1) {
        --cnt[u];
        --sz[u];
        return true;
      }
      if (ls[u] == 0 || rs[u] == 0) {
        u = ls[u] + rs[u];
        return true;
      } else if (p[ls[u]] < p[rs[u]]) {
        rotateR(u);
        return remove(u, x);
      } else {
        rotateL(u);
        return remove(u, x);
      }
    } else if (a[u] < x) {
      bool res = remove(rs[u], x);
      if (res) {
        --sz[u];
      }
      return res;
    } else {
      bool res = remove(ls[u], x);
      if (res) {
        --sz[u];
      }
      return res;
    }
  }

  bool remove(int x) {
    return remove(rt, x);
  }

  int queryRank(int u, int x) {
    if (!u) {
      return 1;
    }
    if (a[u] == x) {
      return sz[ls[u]] + 1;
    } else if (a[u] < x) {
      return sz[ls[u]] + cnt[u] + queryRank(rs[u], x);
    } else {
      return queryRank(ls[u], x);
    }
  }

  int queryRank(int x) {
    return queryRank(rt, x);
  }

  int queryByRank(int u, int x) {
    if (!u) {
      return 0;
    }
    if (x <= sz[ls[u]]) {
      return queryByRank(ls[u], x);
    } else if (x > sz[ls[u]] + cnt[u]) {
      return queryByRank(rs[u], x - sz[ls[u]] - cnt[u]);
    } else {
      return a[u];
    }
  }

  auto queryByRank(int x) {
    return queryByRank(rt, x);
  }

  int queryPrev(int u, int x) {
    int res = notFound;
    while (u) {
      if (a[u] < x) {
        res = a[u];
        u = rs[u];
      } else {
        u = ls[u];
      }
    }
    return res;
  }

  auto queryPrev(int x) {
    return queryPrev(rt, x);
  }

  int queryNext(int u, int x) {
    int res = notFound;
    while (u) {
      if (a[u] > x) {
        res = a[u];
        u = ls[u];
      } else {
        u = rs[u];
      }
    }
    return res;
  }

  auto queryNext(int x) {
    return queryNext(rt, x);
  }
};

struct Fenwick {
  int n;
  vector<int> a;
  Fenwick(int _n) : n(_n), a(_n + 10){};
  void add(int k, int x) {
    while (k <= n) {
      a[k] += x;
      k += k & -k;
    }
  }
  int query(int k) {
    int res = 0;
    while (k > 0) {
      res += a[k];
      k -= k & -k;
    }
    return res;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> cells(k);
  set<int> b;
  int mx = 0;
  for (auto &[x, y] : cells) {
    cin >> x >> y;
    b.insert(x);
    b.insert(y);
    mx = max(mx, x);
  }
  int cid = 0;
  map<int, int> id;
  for (auto x : b) {
    id[x] = ++cid;
  }
  // for (auto &[x, y] : cells) {
  //   x = id[x];
  //   y = id[y];
  // }
  // Fenwick tr(cid + 10);
  Treap tr(cid * 3);
  map<int, pair<int, int>> a;
  for (int i = 0; i < k; ++i) {
    auto [x, y] = cells[i];
    if (a.find(x) == a.end() || y < a[x].first) {
      a[x] = {y, i};
    }
  }
  vector<int> ans(k);
  int ansx = 0;
  int last = n;
  int plus = 0;
  deque<int> pq;
  map<int, pair<int, int>> ers;
  for (auto it = a.rbegin(); it != a.rend(); ++it) {
    auto [x, ind] = it->second;
    int cmi = tr.queryByRank(1);
    if (cmi == 0) {
      cmi = m + 1;
    }
    ansx += (cmi - 1) * (last - it->first);
    pq.emplace_back((m - cmi + 1) * (last - it->first));
    plus += pq.back();
    if (tr.queryPrev(x + 1) == tr.notFound) {
      ers[x] = {it->first, ind};
    }
    tr.insert(x);
    last = it->first;
  }
  int cmi = tr.queryByRank(1);
  if (cmi == 0) {
    cmi = m + 1;
  }
  ansx += (cmi - 1) * (last);
  cout << ansx << endl;
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
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
