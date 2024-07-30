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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (auto &[l, r] : a) {
    cin >> l >> r;
  }
  sort(a.begin(), a.end());
  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    b[i] = i;
  }
  for (auto [l, r] : a) {
    if (r == b[l] + 1) {
      b[l] = r;
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << i << ' ' << b[i] << endl;
  // }
  vector<int> mi(n + 1);
  mi[n] = b[n];
  for (int i = n - 1; i >= 1; --i) {
    mi[i] = min(mi[i + 1], b[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += mi[i] - i + 1;
  }
  cout << ans << endl;
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
