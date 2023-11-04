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
  int n;
  cin >> n;
  vector<double> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto calc = [&](const vector<double> &a) {
    double res = 0;
    double base = 1;
    double low;
    for (int i = 1; i <= a.size(); ++i) {
      res += base * a[a.size() - i];
      low += base;
      base *= 0.9;
    }
    res /= low;
    res -= 1200 / sqrt(a.size());
    return res;
  };
  double ma = -1e9;
  vector<double> ansa;
  for (int i = 1; i < (1ll << n); ++i) {
    vector<double> t;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        t.emplace_back(a[j]);
      }
    }
    auto ta = calc(t);
    if (ta > ma) {
      ma = ta;
      ansa = t;
    }
  }
  for (auto i : ansa) {
    cout << i << ' ';
  }
  cout << endl;
  cout << calc(ansa) << endl;
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
