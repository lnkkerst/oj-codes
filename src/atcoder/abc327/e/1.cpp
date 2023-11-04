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

void solve() {
  int n;
  cin >> n;
  deque<double> a(n);
  vector<double> mi9(n);
  for (auto &i : a) {
    cin >> i;
  }
  mi9[0] = 1;
  for (int i = 1; i < n; ++i) {
    mi9[i] = mi9[i - 1] * 0.9;
  }
  vector<double> dp(n + 1);
  double ans = -1e9;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = dp[i] * 0.9 + a[i];
    for (int j = i; j >= 0; --j) {
      dp[j + 1] = max(0.9 * dp[j] + a[i], dp[j + 1]);
    }
  }
  double w = 0;
  for (int i = 1; i <= n; ++i) {
    w = 0.9 * w + 1;
    ans = max(ans, dp[i] / w - 1200.0 / sqrt(i));
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  int t = 1;
  while (t--) {
    solve();
  }
}
