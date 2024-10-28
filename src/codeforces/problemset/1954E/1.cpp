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
private:
  vector<int> t1, t2;
  int n;

  void add_(int k, int x) {
    int v1 = k * x;
    while (k <= n) {
      t1[k] += x, t2[k] += v1;
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
  Tree(int _n): t1(_n + 2), t2(_n + 2), n(_n) {}

  static int lowbit(int x) {
    return x & -x;
  }

  // 区间加
  void add(int l, int r, int v) {
    add_(l, v);
    add_(r + 1, -v);
  }

  // 求区间和
  int query(int l, int r) {
    return (r + 1) * query_(t1, r) - l * query_(t1, l - 1)
           - (query_(t2, r) - query_(t2, l - 1));
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  Tree tree(mx + 10);
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= a[i - 1]) {
      continue;
    }
    int l = 1, r = 0;
    while (l <= mx) {
      if (l == a[i - 1]) {
        r = a[i - 1];
      } else if (l == a[i]) {
        r = a[i];
      } else {
        if (l >= a[i]) {
          r = mx;
        } else if (l >= a[i - 1]) {
          r = min(mx, (a[i] - 1) / ((a[i] - 1) / l));
        } else {
          r = min(mx, min((a[i] - 1) / ((a[i] - 1) / l),
                          (a[i - 1] - 1) / ((a[i - 1] - 1) / l)));
        }
      }
      int cur = ((a[i] + l - 1) / l) - ((a[i - 1] + l - 1) / l);
      tree.add(l, r, cur);
      l = r + 1;
    }
  }
  for (int i = 1; i <= mx; ++i) {
    cout << tree.query(i, i) << ' ';
  }
  cout << endl;
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
