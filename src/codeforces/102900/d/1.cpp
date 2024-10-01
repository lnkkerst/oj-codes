#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define double long double

void solve() {
  double n, p1, v1, p2, v2;
  cin >> n >> p1 >> v1 >> p2 >> v2;
  double ans = 1e18;
  auto calc1 = [&](double p, double v) {
    int a = p, b = n - p;
    if (a > b) {
      swap(a, b);
    }
    return (a * 2 + b) / v;
  };
  auto calc = [&](double p, double v, double t) {
    auto s = v * t;
    if (s < p) {
      return (double)0;
    }
    return max(p, max(s - p, (s + p) / 2));
  };
  // ans = min(calc1(p1, v1), calc1(p2, v2));
  // ans = min(ans, max((n - p1) / v1, p2 / v2));
  double l = 0, r = 1e18;
  for (int t = 0; t < 200; ++t) {
    double mid = (l + r) / 2;
    double s1 = mid * v1;
    double s2 = mid * v2;
    double tmp = max(calc(p1, v1, mid) + calc(n - p2, v2, mid),
                     calc(n - p1, v1, mid) + calc(p2, v2, mid));
    if (tmp > n) {
      r = mid;
    } else {
      l = mid;
    }
  }
  ans = min(ans, l);
  cout << ans << endl;
  return;

  swap(p1, p2);
  swap(v1, v2);
  // ans = min(calc1(p1, v1), calc1(p2, v2));
  // ans = min(ans, max((n - p1) / v1, p2 / v2));
  l = 0, r = 1e18;
  for (int t = 0; t < 200; ++t) {
    double mid = (l + r) / 2;
    double s1 = mid * v1;
    double s2 = mid * v2;
    // cout << l << ' ' << r << ' ' << mid << endl;
    double tmp = max(calc(p1, v1, mid) + calc(n - p2, v2, mid),
                     calc(n - p1, v1, mid) + calc(p2, v2, mid));
    // cout << tmp << endl;
    if (tmp > n) {
      r = mid;
    } else {
      l = mid;
    }
  }
  ans = min(ans, l);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
