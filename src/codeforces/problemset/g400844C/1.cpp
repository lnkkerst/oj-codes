#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
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
  vector<array<array<int, 3>, 3>> dp(n + 1);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= 2; ++j) {
      for (int k = 0; k <= 2; ++k) {
        dp[i][j][k] = -INT64_MAX / 2;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= 2; ++j) {
      for (int k = 0; k <= 2; ++k) {
        if (k < 2) {
          dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
        }
        if (j < 2) {
          dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
        }
        if (i < n) {
          dp[i + 1][j][k] =
              max(dp[i + 1][j][k],
                  dp[i][j][k] + (j == 1 ? a[i + 1] : 0) * (k == 1 ? x : 1));
        }
      }
    }
  }
  cout << dp[n][2][2] << endl;
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
