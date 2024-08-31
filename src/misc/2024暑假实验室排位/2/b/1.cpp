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
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[0][0] = 0;
  auto pd = [&](int x) {
    x %= h;
    return x >= l && x <= r;
  };
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + pd(p[i] - j));
      if (j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + pd(p[i] - j));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, dp[n][i]);
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
