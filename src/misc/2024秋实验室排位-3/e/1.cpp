#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long
#define double long double

constexpr double EPS = 1e-4;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void solve() {
  int n;
  cin >> n;
  vector<double> a(n + 1);
  double pl = 0.5;
  int mai = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > a[mai]) {
      mai = i;
    }
  }
  for (int x = 1; x <= 10000; ++x) {
    double d = x / a[mai];
    bool fl = true;
    for (int i = 1; i <= n; ++i) {
      int ix = a[i] * d + pl;
      if (ix > 10000 || fabs(a[i] * d - ix) > EPS) {
        fl = false;
        break;
      }
    }
    if (!fl) {
      continue;
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
      ans[i] = a[i] * d + pl;
    }
    int g = ans[1];
    for (int i = 1; i <= n; ++i) {
      g = gcd(g, ans[i]);
    }
    double nd = 0;
    for (int i = 1; i <= n; ++i) {
      nd += ans[i] * ans[i];
    }
    nd = sqrt(nd);
    for (int i = 1; i <= n; ++i) {
      if (fabs(ans[i] / nd - a[i]) > 1e-8) {
        fl = false;
        break;
      }
    }
    if (!fl) {
      continue;
    }
    // cout << x << ' ' << g << endl;
    if (g == 1) {
      for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
      }
      break;
    }
  }
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