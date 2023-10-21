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

constexpr double EPS = 1e-8;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

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
    return;
  }

  double k = (double)(y2 - y1) / (double)(x2 - x1);
  double b = y1 - k * x1;

  int w = abs(x2 - x1);
  int h = abs(y2 - y1);
  int g = gcd(w, h);
  w /= g;
  h /= g;
  bool fl = false;
  if (w == h) {
    cout << x1 + 1 << ' ' << y1 << endl;
    return;
  }
  if (w > h) {
    swap(w, h);
    fl = true;
  }
  int x, y;
  exgcd(w, h, x, y);
  int ax, ay;
  if (!fl) {
    ay = y1 + x;
    double tx = (double)(ay - b) / k;
    if (tx - floor(tx) < ceil(tx) - tx) {
      ax = floor(tx);
    } else {
      ax = ceil(tx);
    }
    cout << ax << ' ' << ay << endl;
  } else {
    ax = x1 + x;
    double ty = (double)k * ax + b;
    if (ty - floor(ty) < ceil(ty) - ty) {
      ay = floor(ty);
    } else {
      ay = ceil(ty);
    }
    cout << ax << ' ' << ay << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(13);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
