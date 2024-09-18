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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, map<int, int>> mp;
  for (int i = 1; i <= k; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    mp[x - 1][y - 1] = c;
  }
  vector<vector<int>> dp((1ll << n) + 1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    dp[1 << i][i] = a[i];
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k < n; ++k) {
          if ((i >> k) & 1) {
            continue;
          }
          dp[i | (1 << k)][k] =
              max(dp[i | (1 << k)][k], dp[i][j] + mp[j][k] + a[k]);
        }
      }
    }
  }
  for (int i = 0; i < (1 << n); ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        ++cnt;
      }
    }
    if (cnt == m) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, dp[i][j]);
      }
    }
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
