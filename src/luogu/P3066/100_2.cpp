#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, t;
  cin >> n >> t;
  vector<vector<int>> fa(n + 1, vector<int>(21));
  vector<int> dep(n + 1);
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 2; i <= n; ++i) {
    int u, w;
    cin >> u >> w;
    fa[i][0] = u;
    e[u].emplace_back(i, w);
  }
  function<void(int)> dfs0 = [&](int u) {
    for (auto [v, w] : e[u]) {
      dep[v] = dep[u] + w;
      dfs0(v);
    }
  };
  dfs0(1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 20; ++j) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
  }
  vector<int> val(n + 1);
  auto get_fa = [&](int u, int k) {
    int x = 0;
    while (k) {
      if (k & 1) {
        u = fa[u][x];
      }
      ++x;
      k >>= 1;
    }
    return u;
  };
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = n * 10;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (dep[i] - dep[get_fa(i, mid)] <= t) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    ++val[i];
    --val[get_fa(i, l + 1)];
  }
  vector<int> ans(n + 1);
  function<void(int)> dfs = [&](int u) {
    ans[u] += val[u];
    for (auto [v, w] : e[u]) {
      dfs(v);
      ans[u] += ans[v];
    }
  };
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << endl;
  }
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
