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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vector<int> sz(n + 1);
  vector<int> ans(n + 1);
  vector<int> c(n + 1);
  function<void(int, int)> dfs0 = [&](int u, int pre) {
    sz[u] = 1;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs0(v, u);
      sz[u] += sz[v];
      c[v] = a[v] xor a[u];
      ans[1] += c[v] * sz[v];
    }
  };
  dfs0(1, 0);
  function<void(int, int)> dfs = [&](int u, int pre) {
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      ans[v] = ans[u];
      ans[v] -= sz[v] * (a[u] xor a[v]);
      ans[v] += (n - sz[v]) * (a[u] xor a[v]);
      dfs(v, u);
    }
  };
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
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
