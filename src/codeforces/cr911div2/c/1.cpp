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
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  vector<int> ls(n + 1), rs(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> ls[i] >> rs[i];
  }
  vector<int> dp(n + 1, 1e9);
  function<void(int, int)> dfs = [&](int u, int pre) {
    if (u == 0) {
      return;
    }
    if (ls[u] == 0 && rs[u] == 0) {
      dp[u] = 0;
      return;
    }
    dfs(ls[u], u);
    dfs(rs[u], u);
    if (s[u] == 'L') {
      dp[u] = min(dp[u], dp[ls[u]]);
      dp[u] = min(dp[u], dp[rs[u]] + 1);
    } else if (s[u] == 'R') {
      dp[u] = min(dp[u], dp[rs[u]]);
      dp[u] = min(dp[u], dp[ls[u]] + 1);
    } else {
      dp[u] = min(dp[u], dp[rs[u]] + 1);
      dp[u] = min(dp[u], dp[ls[u]] + 1);
    }
  };
  dfs(1, 0);
  cout << dp[1] << endl;
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
