#include <ios>
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

inline constexpr double EPS = 1e-8;

auto cross(pair<int, int> a, pair<int, int> b) {
  return a.first * b.second - b.first * a.second;
}

auto div(pair<int, int> a, pair<int, int> b) {
  auto c = a;
  c.first -= b.first;
  c.second -= b.second;
  return c;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  double ans = 1e9;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        auto v1 = div(a[i], a[j]);
        auto v2 = div(a[i], a[k]);
        double v = cross(v1, v2);
        v /= 2;
        v = fabs(v);
        if (fabs(v) > EPS) {
          ans = min(ans, v);
        }
      }
    }
  }
  if (fabs(ans - 1e9) < EPS) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
