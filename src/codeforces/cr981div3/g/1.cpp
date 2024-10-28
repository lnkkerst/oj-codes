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
  vector<vector<int>> e(n + 1);
  vector<array<int, 23>> fa(n + 1);
  auto mx = fa;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vector<vector<pair<int, int>>> h(n + 1);
  vector<int> dep(n + 1);
  dep[0] = -1;
  function<void(int, int)> dfs1 = [&](int u, int pre) {
    dep[u] = dep[pre] + 1;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs1(v, u);
      h[u].emplace_back(h[v][0].first + 1, v);
    }
    while (h[u].size() < 3) {
      h[u].emplace_back(0, -1);
    }
    sort(h[u].begin(), h[u].end(), greater<>());
  };
  dfs1(1, 0);
  function<void(int, int)> dfs = [&](int u, int pre) {
    if (pre == 0) {
      fa[u][0] = u;
    } else {
      fa[u][0] = pre;
    }
    for (int i = 1; i <= 20; ++i) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    if (pre != 0) {
      mx[u][0] = min(1ll, dep[u])
                 + (h[fa[u][0]][0].second == u ? h[fa[u][0]][1].first
                                               : h[fa[u][0]][0].first);
      for (int i = 1; i <= 20; ++i) {
        mx[u][i] = max(mx[u][i - 1],
                       mx[fa[u][i - 1]][i - 1] + min((1ll << (i - 1)), dep[u]));
      }
    }

    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
    }
  };
  dfs(1, 0);

  int q;
  cin >> q;
  while (q--) {
    int u, k;
    cin >> u >> k;
    int ans = h[u][0].first;
    int cur = u;
    for (int i = 0; i <= 20; ++i) {
      if ((k >> i) & 1) {
        ans = max(ans, dep[u] - dep[cur] + mx[cur][i]);
        cur = fa[cur][i];
      }
    }
    cout << ans << ' ';
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
