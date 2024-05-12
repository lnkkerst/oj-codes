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

inline constexpr int MOD = 998244353;

void solve() {
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  string s;
  cin >> s;
  s = " " + s;
  map<int, map<int, int>> mp;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    x -= sx;
    y -= sy;
    if (max(abs(x), abs(y)) > 100) {
      continue;
    }
    mp[x][y] = 1;
  }
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(233, vector<int>(233)));
  dp[0][0 + 101][0 + 101] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    int dx = 0, dy = 0;
    if (s[i] == 'L') {
      dx = -1;
    }
    if (s[i] == 'R') {
      dx = 1;
    }
    if (s[i] == 'U') {
      dy = 1;
    }
    if (s[i] == 'D') {
      dy = -1;
    }
    for (int x = -100; x <= 100; ++x) {
      for (int y = -100; y <= 100; ++y) {
        int nx = x + dx;
        int ny = y + dy;
        if (!mp[nx][ny]) {
          if (!mp[x][y]) {
            dp[i][nx + 101][ny + 101] += dp[i - 1][x + 101][y + 101];
            dp[i][nx + 101][ny + 101] %= MOD;
          }
        } else {
          dp[i][x + 101][y + 101] += dp[i - 1][x + 101][y + 101];
          dp[i][x + 101][y + 101] %= MOD;
        }
      }
    }
    // for (int x = -2; x <= 2; ++x) {
    //   for (int y = -2; y <= 2; ++y) {
    //     cout << dp[i][x + 101][y + 101] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }
  cout << dp[n][0 + 101][0 + 101] << endl;
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
