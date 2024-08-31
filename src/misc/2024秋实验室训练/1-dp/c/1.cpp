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
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  auto cmp = [&](int x, int y) {
    if (x == y) {
      return 0;
    }
    if (x > y) {
      return 1;
    }
    return -1;
  };
  for (int i = 2; i <= n; ++i) {
    if (s[i] == s[i - 1]) {
      dp[i - 1][i] = 0;
    } else {
      dp[i - 1][i] = 1;
    }
  }
  for (int k = 4; k <= n; ++k) {
    for (int l = 1; l + k - 1 <= n; ++l) {
      int r = l + k - 1;
      int cur = 1;

      if (dp[l + 1][r - 1] != 0) {
        cur = min(cur, dp[l + 1][r - 1]);
      } else {
        cur = min(cur, cmp(s[r], s[l]));
      }
      if (dp[l + 2][r] != 0) {
        cur = min(cur, dp[l + 2][r]);
      } else {
        cur = min(cur, cmp(s[l + 1], s[l]));
      }
      dp[l][r] = cur;

      cur = 1;
      if (dp[l + 1][r - 1] != 0) {
        cur = min(cur, dp[l + 1][r - 1]);
      } else {
        cur = min(cur, cmp(s[l], s[r]));
      }
      if (dp[l][r - 2] != 0) {
        cur = min(cur, dp[l][r - 2]);
      } else {
        cur = min(cur, cmp(s[r - 1], s[r]));
      }
      dp[l][r] = max(cur, dp[l][r]);
    }
  }
  cout << vector<string>{"Bob", "Draw", "Alice"}[dp[1][n] + 1] << endl;
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
