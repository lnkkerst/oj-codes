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

inline constexpr int MOD = 1e9 + 7;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= p;
    }
    x *= x;
    x %= p;
    k >>= 1;
  }
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  int su = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    su += a[i];
  }
  vector<int> dp(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = max(dp[i - 1] + a[i], a[i]);
    mx = max(mx, dp[i]);
  }
  mx %= MOD;
  su += mx * (qmi(2, k) - 1) % MOD;
  cout << (su % MOD + MOD) % MOD << endl;
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
