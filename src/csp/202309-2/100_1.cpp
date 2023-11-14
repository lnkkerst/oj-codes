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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<double> scale(n + 1, 1), rotate(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int opt;
    double x;
    cin >> opt >> x;
    if (opt == 1) {
      scale[i] = x;
    } else {
      rotate[i] = x;
    }
  }
  for (int i = 2; i <= n; ++i) {
    scale[i] *= scale[i - 1];
    rotate[i] += rotate[i - 1];
  }
  while (m--) {
    int l, r;
    double x, y;
    cin >> l >> r >> x >> y;
    double cs = scale[r] / scale[l - 1];
    double cr = rotate[r] - rotate[l - 1];
    x *= cs;
    y *= cs;
    double nx = x * cos(cr) - y * sin(cr);
    double ny = x * sin(cr) + y * cos(cr);
    x = nx;
    y = ny;
    cout << x << ' ' << y << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  int t = 1;
  while (t--) {
    solve();
  }
}
