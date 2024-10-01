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
  Tree(int _n): a(_n + 2), n(_n) {}

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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<pair<int, int>> b;
  vector<decltype(b)> ab;

  int ans = -1;

  auto calc = [&](vector<pair<int, int>> a) {
    if (a.empty()) {
      return n;
    }
    // for (auto [l, r] : a) {
    //   cout << l << ' ' << r << endl;
    // }
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    auto [cl, cr] = a.front();
    for (auto [l, r] : a) {
      if (l <= cr) {
        cr = max(cr, r);
      } else {
        b.emplace_back(cl, cr);
        cl = l;
        cr = r;
      }
    }
    b.emplace_back(cl, cr);
    int res = n;
    for (auto [l, r] : b) {
      // cout << "b: " << l << ' ' << r << endl;
      res -= r - l;
    }
    return res;
  };

  bool req = false;
  bool any = false;
  bool fl = false;
  for (int i = 30; i >= 0; --i) {
    int bm = (m >> i) & 1;
    int cnt = 0;
    for (auto x : a) {
      cnt += (x >> i) & 1;
    }
    if (bm == 0 && (cnt & 1)) {
      fl = true;
      break;
    }
    if (bm == 0 && !(cnt & 1)) {
      int last = -1;
      for (int j = 0; j < n; ++j) {
        int bx = (a[j] >> i) & 1;
        if (bx == 1) {
          if (last != -1) {
            b.emplace_back(last, j);
            last = -1;
          } else {
            last = j;
          }
        }
      }
    }
    if (bm == 1 && (cnt & 1)) {}
    if (bm == 1 && !(cnt & 1)) {
      vector<pair<int, int>> t = b;
      int last = -1;
      for (int j = 0; j < n; ++j) {
        int bx = (a[j] >> i) & 1;
        if (bx == 1) {
          if (last != -1) {
            t.emplace_back(last, j);
            last = -1;
          } else {
            last = j;
          }
        }
      }
      ans = max(ans, calc(t));
      ab.emplace_back(t);
    }
  }
  if (!fl) {
    ans = max(ans, calc(b));
  }
  cout << ans << endl;
  return;
  if (any) {
    cout << n << endl;
    return;
  }
  if (req) {
    cout << -1 << endl;
    return;
  }
  if (ab.empty()) {
    // cout << "empty" << endl;
    cout << calc(b) << endl;
    return;
  }
  for (auto &suf : ab) {
    auto t = b;
    for (auto i : suf) {
      t.emplace_back(i);
    }
    ans = max(ans, calc(t));
  }
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
