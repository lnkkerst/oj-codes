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

#define int __int128_t

int read() {
  int x = 0, f = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}

void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}

void solve() {
  int n = read(), m = read();
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = read();
    }
  }
  auto process_row = [&](const vector<int> &a) {
    int n = a.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
      dp[i][i] = a[i] * ((int)1 << n);
    }
    for (int k = 2; k <= n; ++k) {
      for (int i = 1; i + k - 1 <= n; ++i) {
        int l = i;
        int r = i + k - 1;
        dp[l][r] = max(dp[l][r - 1] + a[r] * ((int)1 << (n - k + 1)),
                       dp[l + 1][r] + a[l] * ((int)1 << (n - k + 1)));
      }
    }
    return dp[1][n];
  };
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += process_row(a[i]);
  }
  write(ans);
}

signed main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
