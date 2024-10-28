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
  int n;
  vector<int> tag, sum;
  // intervals 记录线段树上的节点对应的监视器
  vector<vector<int>> intervals;
  // 记录一次操作影响的监视器，三个数分别是监视器序号、线段树节点对应区间大小、节点内个数是
  // 0 还是 1
  vector<tuple<int, int, int>> tmp;

  Tree(int _n)
    : n(_n), tag((_n + 2) * 4), sum((_n + 2) * 4), intervals((_n + 2) * 4) {}
  Tree(const vector<int> &a): Tree(a.size()) {
    function<void(int, int, int)> build = [&](int l, int r, int u) {
      if (l == r) {
        sum[u] = a[l - 1];
        return;
      }
      int mid = (r - l) / 2 + l;
      build(l, mid, ls);
      build(mid + 1, r, rs);
      sum[u] = sum[ls] + sum[rs];
    };
    build(1, n, 1);
  }

  void pushdown(int u, int len) {
    tag[ls] += tag[u];
    tag[rs] += tag[u];
    sum[ls] += tag[u] * ((len + 1) >> 1);
    sum[rs] += tag[u] * (len >> 1);
    tag[u] = 0;
  }

  // 检测区间内个数为 0 或 1
  void check(int u, int len) {
    if (sum[u] == 0 || sum[u] == 1) {
      for (auto x : intervals[u]) {
        tmp.emplace_back(x, len, sum[u]);
      }
    }
  }

  void pushup(int u) {
    sum[u] = sum[ls] + sum[rs];
  }

  void add(int l, int r, int x, int cl = 1, int cr = -1, int u = 1) {
    if (cr == -1) {
      cr = n;
    }
    int len = cr - cl + 1;
    if (cl >= l && cr <= r) {
      tag[u] += x;
      sum[u] += len * x;
      check(u, len);
      return;
    }
    if (tag[u]) {
      pushdown(u, len);
    }
    int mid = ((cr - cl) >> 1) + cl;
    if (l <= mid) {
      add(l, r, x, cl, mid, ls);
    }
    if (r > mid) {
      add(l, r, x, mid + 1, cr, rs);
    }
    pushup(u);
    check(u, len);
  }

  // 将监视器挂到线段树节点上
  void apply_interval(int l, int r, int x, int cl = 1, int cr = -1, int u = 1) {
    if (cr == -1) {
      cr = n;
    }
    int len = cr - cl + 1;
    if (cl >= l && cr <= r) {
      intervals[u].emplace_back(x);
      return;
    }
    int mid = ((cr - cl) >> 1) + cl;
    if (l <= mid) {
      apply_interval(l, r, x, cl, mid, ls);
    }
    if (r > mid) {
      apply_interval(l, r, x, mid + 1, cr, rs);
    }
  }

  // 单次查询
  auto modify(int k) {
    tmp.clear();
    add(k, k, -1, 1, n, 1);
    return tmp;
  }

#undef ls
#undef rs
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> b(m + 1);
  vector<int> cnt(m + 1);
  Tree tree(n + 10);
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].first >> b[i].second;
    ++b[i].first;
    ++b[i].second;
    cnt[i] = b[i].second - b[i].first + 1;
    if (cnt[i] == 1) {
      ans += i * i;
    }
    tree.apply_interval(b[i].first, b[i].second, i);
  }
  auto update = [&](vector<tuple<int, int, int>> a) {
    for (auto [x, len, c] : a) {
      int before = cnt[x];
      if (c == 1) {
        cnt[x] -= len - 1;
      } else {
        cnt[x]--;
      }
      if (cnt[x] == 1 && before != 1) {
        ans += x * x;
      }
      if (cnt[x] == 0 && before == 1) {
        ans -= x * x;
      }
    }
  };
  tree.add(1, n, 1);
  cout << ans << ' ';
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    x = (x + ans) % n;
    update(tree.modify(x + 1));
    cout << ans << ' ';
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
