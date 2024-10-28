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

#define int __int128_t

using ll = long long;
void print(int x) {
  if (x < 0) {
    cout << '-';
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  cout << char(x % 10 + '0');
}

void solve() {
  int n;
  ll _n;
  cin >> _n;
  n = _n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    ll _x;
    cin >> _x;
    a[i] = _x;
    a.emplace_back(a[i]);
  }
  using pii = pair<int, int>;
  vector<pii> dots(n);
  for (int i = 0; i < n; ++i) {
    auto &[x, y] = dots[i];
    ll _x, _y;
    cin >> _x >> _y;
    x = _x;
    y = _y;
    dots.emplace_back(x, y);
  }
  auto calc_area = [&](pii d1, pii d2, pii d3) {
    auto [x1, y1] = d1;
    auto [x2, y2] = d2;
    auto [x3, y3] = d3;
    int area = x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
    if (area < 0) {
      area = -area;
    }
    return area;
  };
  vector<vector<int>> dp(n * 2 + 10, vector<int>(n * 2 + 10));
  for (int k = 3; k <= n; ++k) {
    for (int i = 0; i < n; ++i) {
      int l = i, r = (i + k - 1);
      if (a[l] != a[r]) {
        continue;
      }
      for (int il = l + 1; il <= r - 1; ++il) {
        for (int ir = il; ir <= r - 1; ++ir) {
          if (a[il] != a[ir]) {
            continue;
          }
          if (ir == il) {
            dp[l][r] = max(dp[l][r], calc_area(dots[l], dots[r], dots[il]));
          } else {
            dp[l][r]
              = max(dp[l][r], dp[il][ir] + calc_area(dots[il], dots[l], dots[r])
                                + calc_area(dots[il], dots[ir], dots[r]));
          }
          // cout << l << ' ' << r << ' ' << il << ' ' << ir << ' ' << dp[l][r]
          //      << endl;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n * 2; ++i) {
    for (int j = i; j < n * 2; ++j) {
      ans = max(ans, dp[i][j]);
      // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    }
  }
  print(ans);
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = 1;
  cin >> t;

  while (t--) {
    solve();
  }
}
