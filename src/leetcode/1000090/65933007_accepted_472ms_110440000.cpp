class Solution {
public:
  int minJump(vector<int> &a) {
    vector<int> dp(a.size());
    dp.back() = 1;
    for (int i = dp.size() - 2; i >= 0; --i) {
      if (a[i] + i >= dp.size())
        dp[i] = 1;
      else
        dp[i] = dp[a[i] + i] + 1;
      for (int j = i + 1; j < (int)dp.size() && dp[j] >= dp[i] + 1; ++j)
        dp[j] = dp[i] + 1;
    }
    return dp.front();
  }
};