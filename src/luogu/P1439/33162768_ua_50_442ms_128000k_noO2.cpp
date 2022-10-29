#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> b[i];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (a[i] == b[j]);
  cout << dp.back().back();
  return 0;
}