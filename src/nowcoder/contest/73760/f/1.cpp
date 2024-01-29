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

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    k >>= 1;
  }
  return res % MOD;
}

int inv(int x) {
  return qmi(x, MOD - 2) % MOD;
}

int modf(int x, int y) {
  return x * inv(y) % MOD;
}

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> ca, cb;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++ca[x];
  }
  for (int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    ++cb[x];
  }

  vector<vector<vector<vector<int>>>> dp(
      ca[1] + 1, vector<vector<vector<int>>>(
                     ca[2] + 1, vector<vector<int>>(
                                    cb[1] + 1, vector<int>(cb[2] + 1, -1))));

  function<int(int, int, int, int)> dfs = [&](int ca1, int ca2, int cb1,
                                              int cb2) -> int {
    if (ca1 == 0 && ca2 == 0) {
      return 0;
    }
    if (cb1 == 0 && cb2 == 0) {
      return 0;
    }
    if (ca1 == 0 && cb1 == 0) {
      return 0;
    }
    if (ca2 == 0 && cb2 == 0) {
      return 0;
    }
    if (dp[ca1][ca2][cb1][cb2] != -1) {
      return dp[ca1][ca2][cb1][cb2];
    }
    int res = 1;
    int p1 = 0;
    if (ca1) {
      p1 = modf(ca1, ca1 + ca2) * modf(cb2, cb1 + cb2) % MOD;
      res += p1 * dfs(ca1 - 1, ca2, cb1, cb2);
      res %= MOD;
    }
    int p2 = 0;
    if (cb1) {
      p2 = modf(ca2, ca1 + ca2) * modf(cb1, cb1 + cb2) % MOD;
      res += p2 * dfs(ca1, ca2, cb1 - 1, cb2) % MOD;
      res %= MOD;
    }
    if (p1 || p2) {
      res = modf(res, (p1 + p2) % MOD) % MOD;
    }
    dp[ca1][ca2][cb1][cb2] = res;
    return dp[ca1][ca2][cb1][cb2];
  };
  cout << dfs(ca[1], ca[2], cb[1], cb[2]) << endl;
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
