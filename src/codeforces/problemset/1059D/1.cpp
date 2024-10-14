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

constexpr double EPS = 1e-7;

struct Node {
  double x;
  double y;
};

void solve() {
  int n;
  cin >> n;

  vector<Node> a(n);
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    if (a[i].y > 0) {
      ++ans;
    } else {
      a[i].y = -a[i].y;
    }
  }
  if (ans && ans != n) {
    cout << -1 << endl;
    return;
  }
  double l = 0, r = 1e16;
  while (r - l > EPS) {
    double mid = (l + r) / 2;
    double cl = -1e7;
    double cr = 1e7;
    bool fl = true;
    for (int i = 0; i < n; ++i) {
      if (mid < a[i].y - mid) {
        fl = false;
        break;
      }
      double tmp = sqrt(mid + mid - a[i].y) * sqrt(a[i].y);
      double li = a[i].x - tmp;
      double ri = a[i].x + tmp;
      cl = max(cl, li);
      cr = min(cr, ri);
      if (cl > cr) {
        fl = false;
        break;
      }
    }
    if (fl) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(10) << l << endl;
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
