#pragma GCC optimize(2)
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  auto calc = [&](int m) {
    vector<int> dp(n + 1);
    vector<int> last(233);
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1];
      if (m - a[i] > 100 || m - a[i] <= 0 || last[m - a[i]] == 0) {
        last[a[i]] = i;
        continue;
      }
      dp[i] = max(dp[i], dp[last[m - a[i]] - 1] + 1);
      last[a[i]] = i;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res = max(res, dp[i]);
    }
    return res;
  };
  int ans = 0;
  for (int i = 1; i <= 200; ++i) {
    ans = max(ans, calc(i));
  }
  cout << ans * 2 << endl;
}
