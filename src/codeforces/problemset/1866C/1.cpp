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

constexpr int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> e(n + 1);
  for (int u = 1; u <= n; ++u) {
    int s;
    cin >> s;
    for (int i = 1; i <= s; ++i) {
      int v, w;
      cin >> v >> w;
      e[u].emplace_back(v, w);
    }
  }
  vector<int> vis(n + 1);
  vector<vector<int>> cnt(n + 1, vector<int>(2));
  vector<int> ans(n + 1);
  function<void(int)> dfs = [&](int u) {
    if (vis[u]) {
      return;
    }
    vis[u] = true;
    for (auto [v, w] : e[u]) {
      if (w == 0) {
        ans[u] += cnt[u][2];
      }
      cnt[u][w]++;
      dfs(v);
      ans[u] = (ans[u] + cnt[u][1] * cnt[v][0]) % MOD;
      ans[u] = (ans[u] + ans[v]) % MOD;
      cnt[u][0] = (cnt[u][0] + cnt[v][0]) % MOD;
      cnt[u][1] = (cnt[u][1] + cnt[v][1]) % MOD;
    }
  };
  dfs(1);
  // for (int i = 1; i <= n; ++i) {
  //   cout << ans[i] << ' ';
  // }
  // cout << endl;
  cout << ans[1] << endl;
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
