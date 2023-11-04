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

double EPS = 1e-8;

struct Point {
  double x, y;
  Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  Point operator-(const Point &b) { return {x - b.x, y - b.y}; }
  double operator*(const Point &b) { return x * b.y - b.x * y; }
  bool operator<(const Point &b) {
    if (fabs(x - b.x) < EPS) {
      return y < b.y;
    }
    return x < b.x;
  }
};

double dis(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void solve() {
  int n;
  cin >> n;
  vector<Point> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  sort(a.begin(), a.end());
  vector<Point> p;
  for (int i = 0; i < n; ++i) {
    while (p.size() >= 2 &&
           (p[p.size() - 1] - p[p.size() - 2]) * (a[i] - p[p.size() - 2]) <=
               0) {
      p.pop_back();
    }
    p.emplace_back(a[i]);
  }
  int k = p.size();
  for (int i = n - 2; i >= 0; --i) {
    while (p.size() > k &&
           (p[p.size() - 1] - p[p.size() - 2]) * (a[i] - p[p.size() - 2]) <=
               0) {
      p.pop_back();
    }
    p.emplace_back(a[i]);
  }
  if (n > 1) {
    p.pop_back();
  }
  double ans = 0;
  for (int i = 1; i < p.size(); ++i) {
    ans += dis(p[i - 1], p[i]);
  }
  ans += dis(p.front(), p.back());
  cout << fixed << setprecision(2) << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
