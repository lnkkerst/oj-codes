#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

constexpr int MOD = 998244353;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = (res * x) % MOD;
    }
    x = (x * x) % MOD;
    k >>= 1;
  }
  return res;
}

int inv(int x, int p = MOD) { return qmi(x, MOD - 2); }

vector<vector<int>> dp(3010, vector<int>(3010, -1));

int dfs(int i, int j) {
  if (i == j) {
    return 0;
  }
  if (i <= 0 || j < 0) {
    return 0;
  }
  if (i < j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  dp[i][j] = (dfs(i - 1, j) + 1) * (i - j) % MOD * inv(i) % MOD +
             (dfs(i - 1, j - 1) + 2) * j % MOD * inv(i) % MOD;
  return dp[i][j] %= MOD;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ca = 0, cb = 0;
  for (auto i : s) {
    ca += i == 'A';
    cb += i == 'B';
  }
  cout << (dfs(ca, (n / 2 + k - cb) / 2) + dfs(cb, (k + n / 2 - ca) / 2)) % MOD
       << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
