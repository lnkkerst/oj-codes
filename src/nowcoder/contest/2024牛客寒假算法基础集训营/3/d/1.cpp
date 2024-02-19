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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  auto calc = [&](const vector<int> &a) {
    int res = -1e18;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = max(dp[i - 1] + a[i], a[i]);
      res = max(res, dp[i]);
    }
    return res;
  };
  int ans = calc(a);
  if (k) {
    for (int i = 2; i <= n; ++i) {
      swap(a[i], a[i - 1]);
      ans = max(ans, calc(a));
      swap(a[i], a[i - 1]);
    }
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
