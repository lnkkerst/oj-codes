
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
  vector<int> a;
  int n;
  Tree(int _n) : a(_n + 2), n(_n) {
  }

  void add(int pos, int val) {
    while (pos <= n) {
      a[pos] += val;
      pos += pos & -pos;
    }
  }

  int query(int pos) {
    int res = 0;
    while (pos > 0) {
      res += a[pos];
      pos -= pos & -pos;
    }
    return res;
  }

  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<Tree> tr(39);
  for (int i = 0; i <= 30; ++i) {
    for (int j = 1; j <= n; ++j) {
      int bi = (a[j] >> i) & 1;
      tr[i].add(j, bi);
    }
  }

  bool fl = false;

  function<int(int, int, int)> resolve = [&](int l, int r,
                                             int top = 30) -> int {
    if (fl) {
      return 0;
    }
    for (int i = top; i >= 0; --i) {
      int bm = (m >> i) & 1;
      int cnt = tr[i].query(l, r);
      if (bm == 1) {
        if (cnt & 1) {
          continue;
        } else {
          return r - l + 1;
        }
      }
    }
  };
  if (fl) {
    cout << -1 << endl;
    return;
  }
  for (int i = 30; i >= 0; --i) {
    int cnt = 0;
    int bm = (m >> i) & 1;
    for (auto x : a) {
      cnt += (x >> i) & 1;
    }
    if (bm == 0) {
      if (cnt & 1) {
        cout << -1 << endl;
        return;
      }
    } else {
      if (cnt == 0) {
        ans = max(ans, n);
      }
    }
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
