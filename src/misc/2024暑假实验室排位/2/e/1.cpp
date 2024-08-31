#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = " " + s;
  vector<vector<int>> last(n + 1, vector<int>(26, -1));
  for (int i = 1; i <= n; ++i) {
    last[i] = last[i - 1];
    last[i][s[i] - 'a'] = i;
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    dp[i][1] = 1;
  }
  for (int k = 2; k < n; ++k) {
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (last[i - 1][j] != -1) {
          dp[i][k] = min(LONG_LONG_MAX, dp[i][k] + dp[last[i - 1][j]][k - 1]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = n; i >= 2; --i) {
    int cnt = 0;
    for (int j = 0; j < 26; ++j) {
      if (last[n][j] != -1) {
        cnt += dp[last[n][j]][i];
      }
    }
    if (cnt >= k) {
      ans += k * (n - i);
      k = 0;
      break;
    } else {
      ans += cnt * (n - i);
      k -= cnt;
    }
  }

  if (k == 1) {
    ans += n;
    --k;
  }

  if (k > 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
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
