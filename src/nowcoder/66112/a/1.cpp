#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

constexpr int INF = 2e9;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = k - 1;
  vector<vector<int>> dp(n, vector<int>(n));
  for (int k = 2; k <= n; ++k) {
    for (int i = 0; i <= n - k; ++i) {
      int j = i + k - 1;
      dp[i][j] = INF;
      if (i + 1 != j && s[i + 1] == s[j]) {
        dp[i][j] = min(dp[i][j], dp[i + 1][j]);
      }
      if (j - 1 != i && s[i] == s[j - 1]) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      }
      ++dp[i][j];
      if (s[i] == s[j]) {
        dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
      }
      cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (dp[i][j] >= INF) {
        continue;
      }
      int t = dp[i][j] + max(0ll, k - (dp[i][j] + j - i + 1));
      if (t < ans) {
        cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      }
      ans = min(ans, dp[i][j] + max(0ll, k - (dp[i][j] + j - i + 1)));
    }
  }
  cout << ans << endl;
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
