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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    a.emplace_back(a[i]);
  }
  n *= 2;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int k = 2; k <= n; ++k) {
    for (int i = 1; i + k - 1 <= n; ++i) {
      int l = i;
      int r = i + k - 1;
      for (int j = l + 1; j <= r; ++j) {
        dp[l][r] =
            max(dp[l][r], dp[l][j - 1] + dp[j][r] + a[l] * a[j] * a[r % n + 1]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n / 2; ++i) {
    ans = max(ans, dp[i][i + n / 2 - 1]);
  }
  cout << ans << endl;
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
