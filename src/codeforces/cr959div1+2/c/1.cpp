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
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + a[i];
  }
  vector<pair<int, int>> f(n + 1, {-1, -1});
  function<pair<int, int>(int)> dfs = [&](int k) {
    if (k > n) {
      return make_pair(0ll, 0ll);
    }
    if (f[k].first != -1) {
      return f[k];
    }
    int cur = 0, cnt = 0, tot = 0;
    auto it = upper_bound(p.begin() + k, p.end(), p[k - 1] + x);
    if (it == p.end()) {
      f[k] = {0, 0};
    } else {
      int nx = (it - p.begin());
      auto [x, y] = dfs(nx + 1);
      x += 1;
      y += n - nx + 1;
      f[k] = {x, y};
    }
    return f[k];
  };
  int ans = n * (n + 1) / 2;
  for (int i = 1; i <= n; ++i) {
    auto [x, y] = dfs(i);
    ans -= x;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
