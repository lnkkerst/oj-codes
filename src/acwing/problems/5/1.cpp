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
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1), w(n + 1), s(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i] >> s[i];
  }
  vector<int> dp(m + 1);
  auto process_01 = [&](int v, int w) {
    for (int i = m; i >= w; --i) {
      dp[i] = max(dp[i], dp[i - w] + v);
    }
  };
  for (int i = 1; i <= n; ++i) {
    int base = 1;
    int cs = s[i], cw = w[i], cv = v[i];
    while (cs > base) {
      cs -= base;
      process_01(cv * base, cw * base);
      base *= 2;
    }
    process_01(cv * cs, cw * cs);
  }
  cout << dp[m] << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
