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
  int w, f;
  cin >> w >> f;
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    tot += a[i];
  }
  vector<int> dp(tot + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int w = tot; w - a[i] >= 0; --w) {
      if (dp[w - a[i]]) {
        dp[w] = true;
      }
    }
  }
  int ans = 2e9;
  for (int i = 0; i <= tot; ++i) {
    if (dp[i]) {
      ans = min(ans, max((i + w - 1) / w, (tot - i + f - 1) / f));
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
