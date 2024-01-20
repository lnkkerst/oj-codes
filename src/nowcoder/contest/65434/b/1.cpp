#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

constexpr double EPS = 1e-8;

struct Point {
  double x, y;
  bool operator<(const Point &b) const {
    if (fabs(b.x - x) <= EPS) {
      return y < b.y;
    }
    return x < b.x;
  }
};

double distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

Point midpoint(Point p1, Point p2) {
  Point mid;
  mid.x = (p1.x + p2.x) / 2.0;
  mid.y = (p1.y + p2.y) / 2.0;
  return mid;
}

Point findCenter(Point a, Point b, Point c) {
  double p1 = 2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x);
  double p2 = 2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x);
  if (p1 == 0 || p2 == 0) {
    return {0, 0};
  }
  double t1 = a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
  double t2 = a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;
  double cx = (t1 * (a.y - c.y) - t2 * (a.y - b.y)) / p1;
  double cy = (t1 * (a.x - c.x) - t2 * (a.x - b.x)) / p2;
  return {cx, cy};
}

void solve() {
  int n;
  cin >> n;
  vector<Point> a(n);
  for (auto &i : a) {
    cin >> i.x >> i.y;
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    map<Point, int> cnt;
    for (int j = 0; j < n; ++j) {
      Point c = findCenter({0, 0}, a[i], a[j]);
      if (fabs(c.x) < EPS && fabs(c.y) < EPS) {
        continue;
      }
      ++cnt[c];
    }
    for (auto [_, x] : cnt) {
      ans = max(ans, x + 1);
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
