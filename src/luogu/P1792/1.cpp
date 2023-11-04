#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

struct Tree {
private:
  vector<int> t1, t2;
  int n;

  void add_(int k, int v) {
    int v1 = k * v;
    while (k <= n) {
      t1[k] += v, t2[k] += v1;
      k += lowbit(k);
    }
  }

  int query_(vector<int> &t, int k) {
    int res = 0;
    while (k) {
      res += t[k];
      k -= lowbit(k);
    }
    return res;
  }

public:
  Tree(int _n) : t1(_n + 2), t2(_n + 2), n(_n) {}

  static int lowbit(int x) { return x & -x; }

  // 区间加
  void add(int l, int r, int v) {
    add_(l, v);
    add_(r + 1, -v);
  }

  // 求区间和
  int query(int l, int r) {
    return (r + 1) * query_(t1, r) - l * query_(t1, l - 1) -
           (query_(t2, r) - query_(t2, l - 1));
  }
};

struct Node {
  int l, r;
  int id;
  bool operator<(const Node &b) const { return r < b.r; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Tree tr(n);
  int m;
  cin >> m;
  vector<Node> q(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].l >> q[i].r;
    q[i].id = i;
  }
  sort(q.begin() + 1, q.end());
  unordered_map<int, int> last;
  vector<int> ans(m + 1);
  for (int i = 1; i <= m; ++i) {
    for (int j = q[i - 1].r + 1; j <= q[i].r; ++j) {
      if (last[a[j]]) {
        tr.add(last[a[j]], last[a[j]], -1);
      }
      tr.add(j, j, 1);
      last[a[j]] = j;
    }
    ans[q[i].id] = tr.query(q[i].l, q[i].r);
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << endl;
  }
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
