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

constexpr int INF = 1e18;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> w(n + 1), v(n + 1);
  map<int, int> b;
  for (int i = 1; i <= m; ++i) {
    int v, w;
    cin >> v >> w;
    for (int j = 1; j <= n + 10; ++j) {
      int nv = (v * j) % n;
      int nw = w * j;
      if (b[nv] == 0) {
        b[nv] = nw;
      } else {
        b[nv] = min(b[nv], nw);
      }
    }
  }
  vector<int> dp(n * 10 + 1, INF);
  dp[0] = 0;
  for (auto [v, w] : b) {
    cout << v << ' ' << w << endl;
    for (int j = v; j <= n * 10; ++j) {
      dp[j] = min(dp[j], dp[j - v] + w);
    }
  }
  int ans = INF;
  for (int i = 0; i <= 9; ++i) {
    ans = min(ans, dp[n - k + n * i]);
  }
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
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
