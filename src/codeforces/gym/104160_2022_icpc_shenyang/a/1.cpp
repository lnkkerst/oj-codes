#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
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

constexpr double EPS = 1e-9;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n), b(m);
  int tota = 0, totb = 0;
  for (auto &[l, r] : a) {
    cin >> l >> r;
    tota += r - l;
  }
  for (auto &[l, r] : b) {
    cin >> l >> r;
    totb += r - l;
  }
  vector<int> pa(n), pa2(n);
  pa[0] = a[0].second - a[0].first;
  double ans = 0;
  for (auto [l1, r1] : a) {
    for (auto [l2, r2] : b) {
      ans += abs(
        0.5
        * ((r1 * r1 - l1 * l1) * (r2 - l2) + (l2 * l2 - r2 * r2) * (r1 - l1)));
    }
  }
  cout << fixed << setprecision(14) << ans / tota / totb << endl;
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
