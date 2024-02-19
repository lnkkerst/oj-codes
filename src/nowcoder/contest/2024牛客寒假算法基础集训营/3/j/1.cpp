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

constexpr int MOD = 1e9 + 7;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    k >>= 1;
  }

  return res;
}

int inv(int x) {
  return qmi(x, MOD - 2) % MOD;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> p(k);
  vector<vector<double>> a, b;
  for (auto &[u, v] : p) {
    cin >> u >> v;
  }
  auto calc = [&](int n) {
    map<int, int> b;
    for (auto [u, v] : p) {
      ++b[u];
    }
    vector<vector<double>> a(n + 1);
    for (auto [u, v] : p) {
      a[v].emplace_back(1. - (1. / b[u]));
    }
    double res = 0;
    for (int i = 1; i <= n; ++i) {
      double x = 1;
      for (auto y : a[i]) {
        x *= y;
      }
      res += 1 - x;
    }
    return res;
  };
  double ans2 = calc(m);
  for (auto &[u, v] : p) {
    swap(u, v);
  }
  double ans1 = calc(n);
  cout << "float" << endl;
  cout << ans1 << ' ' << ans2 << endl;
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
