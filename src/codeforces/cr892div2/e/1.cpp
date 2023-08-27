#pragma GCC optimize(2)

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  vector<int> ma1(n + 1, -1e14), ma2 = ma1;
  vector<int> mi1(n + 1, 1e14), mi2 = mi1;
  auto calc = [&](int l, int r) { return abs(b[l] - a[r]) + abs(b[r] - a[l]); };
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i && j <= k; ++j) {
      if (i != 0) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] = max(dp[i][j], b[i - 1] + a[i - 1] - mi1[i - j]);
        dp[i][j] = max(dp[i][j], -b[i - 1] - a[i - 1] + ma1[i - j]);
        dp[i][j] = max(dp[i][j], a[i - 1] - b[i - 1] - mi2[i - j]);
        dp[i][j] = max(dp[i][j], b[i - 1] - a[i - 1] + ma2[i - j]);
      }
      if (i != n) {
        mi1[i - j] = min(mi1[i - j], b[i] + a[i] - dp[i][j]);
        ma1[i - j] = max(ma1[i - j], b[i] + a[i] + dp[i][j]);
        mi2[i - j] = min(mi2[i - j], b[i] - a[i] - dp[i][j]);
        ma2[i - j] = max(ma2[i - j], b[i] - a[i] + dp[i][j]);
      }
    }
  }
  cout << dp[n][k] << endl;
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
