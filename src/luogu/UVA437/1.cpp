#include <utility>
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

void solve(int n, int cs) {
  using pii = pair<int, int>;
  vector<pair<pii, int>> a;
  for (int i = 1; i <= n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    a.emplace_back(make_pair(min(x, y), max(x, y)), z);
    a.emplace_back(make_pair(min(x, z), max(x, z)), y);
    a.emplace_back(make_pair(min(y, z), max(y, z)), x);
  }
  n = a.size();
  vector<int> dp(n);
  function<int(int)> dfs = [&](int u) {
    if (dp[u]) {
      return dp[u];
    }
    dp[u] = a[u].second;
    int mx = 0;
    auto [csz, clen] = a[u];
    auto [cw, ch] = csz;
    for (int i = 0; i < n; ++i) {
      auto [sz, len] = a[i];
      auto [w, h] = sz;
      if (w < cw && h < ch) {
        mx = max(mx, dfs(i));
      }
    }
    dp[u] += mx;
    return dp[u];
  };
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, dfs(i));
  }
  cout << "Case " << cs << ": maximum height = " << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int cs = 0;
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    solve(n, ++cs);
  }
}
