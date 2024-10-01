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

// 权值线段树
struct Tree {
#define ls getLs(u)
#define rs getRs(u)

private:
  // n 是最多元素总数，[mi, ma] 是值域
  int n;
  int mi, ma;
  vector<int> a, sum;
  vector<int> lson, rson;
  int cnt = 1;

  int getLs(int u) {
    if (!lson[u]) {
      lson[u] = ++cnt;
    }
    return lson[u];
  }

  int getRs(int u) {
    if (!rson[u]) {
      rson[u] = ++cnt;
    }
    return rson[u];
  }

  void pushdown(int u, int len) {
    a[ls] += a[u];
    a[rs] += a[u];
    sum[ls] += a[u] * ((len + 1) >> 1);
    sum[rs] += a[u] * (len >> 1);
    a[u] = 0;
  }

  void pushup(int u) {
    sum[u] = sum[ls] + sum[rs];
  }

  void add(int l, int r, int L, int R, int x, int u) {
    int len = r - l + 1;
    if (l >= L && r <= R) {
      a[u] += x;
      sum[u] += len * x;
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
      return sum[u];
    }
    if (a[u]) {
      pushdown(u, len);
    }
    int mid = ((r - l) >> 1) + l, res = 0;
    if (L <= mid) {
      res += query(l, mid, L, R, ls);
    }
    if (R > mid) {
      res += query(mid + 1, r, L, R, rs);
    }
    return res;
  }

public:
  Tree(int _n, int _mi, int _ma): n(_n), mi(_mi), ma(_ma) {
    a = sum = lson = rson = vector<int>((_n + 2) * 2);
  }

  void add(int l, int r, int x) {
    return add(mi, ma, l, r, x, 1);
  }

  int query(int l, int r) {
    return query(mi, ma, l, r, 1);
  }

#undef ls
#undef rs
};

void solve() {
  int n, m;
  cin >> n >> m;
  int mi = -2e5;
  int ma = 2e5;
  Tree xt(n * 10, mi, ma), yt(n * 10, mi, ma);
  int xc, yc;
  cin >> yc >> xc;
  vector<int> ax(xc), ay(yc);
  for (int i = 0; i < yc; ++i) {
    cin >> ay[i];
    yt.add(ay[i], ay[i], 1);
  }
  for (int i = 0; i < xc; ++i) {
    cin >> ax[i];
    xt.add(ax[i], ax[i], 1);
  }
  sort(ax.begin(), ax.end());
  sort(ay.begin(), ay.end());
  int ans = 0;
  ans += (xt.query(-n + 1, n - 1) + 1) * (yt.query(m + 1, n - 1) + 1);
  ans += (xt.query(-n + 1, n - 1) + 1) * (yt.query(-n + 1, -m - 1) + 1);
  int xd = xt.query(-n + 1, -m - 1) + xt.query(m + 1, n - 1);
  int yd = yt.query(-m, m);
  ans += (yd - 1) * (xd + 2);
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
