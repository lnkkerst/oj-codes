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
constexpr double EPS = 1e-9;

void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n + 1);
  vector<int> b(m + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  auto calc = [&](const vector<int> ba, int x) {
    int n = ba.size() - 1;
    double l = 0, r = 1e5;
    while (fabs(r - l) > EPS) {
      double mid = (l + r) / 2;
      vector<double> a(n + 1);
      for (int i = 1; i <= n; ++i) {
        a[i] = ba[i] - mid;
      }
      vector<double> p(n + 1);
      vector<double> mi(n + 1);
      auto check = [&]() {
        for (int i = 1; i <= n; ++i) {
          p[i] = p[i - 1] + a[i];
          mi[i] = min(mi[i - 1], p[i]);
          if (i >= x) {
            if (p[i] - mi[i - x] > EPS) {
              return true;
            }
          }
        }
        return false;
      };
      if (check()) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  };
  double ca = calc(a, x);
  double cb = calc(b, y);
  cout << fixed << setprecision(12) << ca + cb << endl;
  // vector<vector<int>> w(n + 1, vector<int>(m + 1));
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     w[i][j] = a[i] + b[j];
  //     cout << w[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
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
