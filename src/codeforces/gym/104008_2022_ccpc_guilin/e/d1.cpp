
#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
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

constexpr double EPS = 1e-8;

double calcDis(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double calc(double x1, double y1, double x2, double y2, double x3, double y3) {
  double d1 = calcDis(x1, y1, x2, y2);
  double d2 = calcDis(x2, y2, x3, y3);
  double d3 = calcDis(x3, y3, x1, y1);
  double p = (d1 + d2 + d3) / 2.0;
  return sqrt(p * (p - d1) * (p - d2) * (p - d3));
}

void solve() {
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  if (x1 == x2) {
    cout << x1 + 1 << ' ' << 0 << endl;
    return;
  }

  if (y1 == y2) {
    cout << 0 << ' ' << y1 + 1 << endl;
  }

  double k = (double)(y2 - y1) / (double)(x2 - x1);
  double b = y1 - k * x1;
  if (y1 > y2) {
    swap(y1, y2);
    swap(x1, x2);
  }
  double ans = 2e18;

  for (int i = y1; i <= y2; ++i) {
    double x = (i - b) / k;
    int tans = min(calc(x1, y1, x2, y2, floor(x), i),
                   calc(x1, y1, x2, y2, ceil(x), i));
    cout << tans << endl;
    if (tans < EPS) {
      continue;
    }
    ans = min(ans, min(calc(x1, y1, x2, y2, floor(x), i),
                       calc(x1, y1, x2, y2, ceil(x), i)));
  }
  cout << ans << endl;
  return;

  int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
  int dy[] = {-1, 0, 1, 0, 1, -1, 1, -1};
  int ax = 0, ay = 0;
  for (int i = 0; i < 8; ++i) {
    int x3 = x1 + dx[i];
    int y3 = y1 + dy[i];
    if (x3 == x2 && y3 == y2) {
      continue;
    }
    double ta = calc(x1, y1, x2, y2, x3, y3);
    cout << x3 << ' ' << y3 << ' ' << ta << endl;
    if (ta < EPS) {
      continue;
    }
    if (ta < ans) {
      ans = ta;
      ax = x3;
      ay = y3;
    }
  }
  for (int i = 0; i < 8; ++i) {
    int x3 = x2 + dx[i];
    int y3 = y2 + dy[i];
    if (x3 == x1 && y3 == y1) {
      continue;
    }
    double ta = calc(x1, y1, x2, y2, x3, y3);
    cout << x3 << ' ' << y3 << ' ' << ta << endl;
    if (ta < EPS) {
      continue;
    }
    if (ta < ans) {
      ans = ta;
      ax = x3;
      ay = y3;
    }
  }
  cout << ax << ' ' << ay << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
