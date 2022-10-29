#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k, MOD = 10000;
  cin >> n >> k;
  vector<int> a(k + 2);
  vector<vector<int>> dp(n + 2, vector<int>(k + 2, 0));
  dp[1][0] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= k; ++j)
      a[j + 1] = (a[j] + dp[i - 1][j]) % MOD;
    for (int j = 0; j <= k; ++j) {
      if (j >= i)
        dp[i][j] = (a[j + 1] - a[j - i + 1] + MOD) % MOD;
      else
        dp[i][j] = a[j + 1] % MOD;
    }
  }
  cout << dp[n][k];
  return 0;
}