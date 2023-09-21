#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (min(n, m) > 3) {
    cout << -1 << endl;
    return;
  }
  if (min(n, m) == 1) {
    cout << 0 << endl;
    return;
  }
  for (auto &i : a) {
    for (auto &j : i) {
      j -= '0';
    }
  }
  vector<vector<int>> b(1 << n, vector<int>(1 << n, 0));
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      bool fl = false;
      for (int k = 0; k < n - 1; ++k) {
        int bits = (bool)(i & (1 << k)) + (bool)(i & (1 << (k + 1)));
        bits += (bool)(j & (1 << k)) + (bool)(j & (1 << (k + 1)));
        if (bits % 2 == 0) {
          fl = true;
        }
      }
      if (!fl) {
        b[i][j] = 1;
      }
    }
  }
  vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));
  for (int i = 1; i <= m; ++i) {
    int mask = 0;
    for (int j = 0; j < n; ++j) {
      mask += a[j][i - 1] << j;
    }
    for (int cur = 0; cur < (1 << n); ++cur) {
      dp[i][cur] = 1e9;
      for (int prev = 0; prev < (1 << n); ++prev) {
        if (!b[prev][cur]) {
          continue;
        }
        dp[i][cur] = min(dp[i][cur],
                         dp[i - 1][prev] + (int)bitset<5>(cur ^ mask).count());
      }
    }
  }
  int ans = 1e9;
  for (int i = 0; i < (1 << n); ++i) {
    ans = min(ans, dp[m][i]);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
