class Solution {
public:
  int waysToChange(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (auto i : {25, 10, 5, 1}) {
      for (int j = i; j <= n; ++j) {
        dp[j] += dp[j - i];
        dp[j] %= (int)1e9 + 7;
      }
    }
    return dp[n];
  }
};