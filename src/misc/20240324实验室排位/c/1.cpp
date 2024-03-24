#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long

inline constexpr int MOD = 1e9 + 7;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= p;
    }
    x *= x;
    x %= p;
    k >>= 1;
  }
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    e[u].emplace_back(v, x);
    e[v].emplace_back(u, x);
  }
  vector<int> q;
  function<int(int, int)> dfs = [&](int u, int pre) -> int {
    int cnt = 1;
    for (auto [v, x] : e[u]) {
      if (v == pre) {
        continue;
      }
      int nx = dfs(v, u);
      if (x == 1) {
        q.emplace_back(nx);
      } else {
        cnt += nx;
      }
    }
    return cnt;
  };
  q.emplace_back(dfs(1, 0));

  int ans = qmi(n, k);
  for (auto x : q) {
    ans -= qmi(x, k);
    ans %= MOD;
  }
  ans = (ans % MOD + MOD) % MOD;
  cout << ans << endl;
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

  return 0;
}
