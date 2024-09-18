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

constexpr int MOD = 1e9 + 7;

void solve() {
  int n, k, q;
  cin >> q >> k;
  n = 1e5;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if (i - k >= 0) {
      dp[i] += dp[i - k];
      dp[i] %= MOD;
    }
  }
  vector<int> p(n + 1);
  p[0] = dp[0];
  for (int i = 1; i <= n; ++i) {
    p[i] = (p[i - 1] + dp[i]) % MOD;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << ((p[r] - p[l - 1]) % MOD + MOD) % MOD << endl;
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
