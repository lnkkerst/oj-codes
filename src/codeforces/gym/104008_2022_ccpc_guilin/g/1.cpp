#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

struct Node {
  using Tree = tree<int, null_type, greater_equal<>, rb_tree_tag,
                    tree_order_statistics_node_update>;
  Tree tr;
  void insert(int x) {
    tr.insert(x);
  }
  void remove(int x) {
    tr.erase(tr.upper_bound(x + 1));
  }
  int operator[](int i) const {
    if (i >= tr.size()) {
      return 0;
    }
    return *tr.find_by_order(i);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<vector<int>> e(n + 1);
  vector<int> fa(n + 1);
  vector<vector<int>> son(n + 1);
  vector<int> h(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vector<Node> dp1(n + 1), dp2(n + 1);
  function<void(int, int)> dfs0 = [&](int u, int from) {
    fa[u] = from;
    h[u] = a[u];
    for (int v : e[u]) {
      if (v == from) {
        continue;
      }
      son[u].emplace_back(v);
      dfs0(v, u);
      h[u] = max(h[u], h[v] + a[u]);
      dp1[u].insert(h[v]);
      dp2[u].insert(dp2[v][0]);
    }
    dp2[u].insert(dp1[u][0] + a[u] + dp1[u][1]);
  };
  dfs0(1, 0);
  int ans = 0;
  function<void(int)> dfs = [&](int u) {
    int ta = 0;
    for (int i = 0; i < 4; ++i) {
      ta += dp1[u][i];
    }
    ans = max(ans, ta);
    for (auto v : son[u]) {
      int d21 = dp1[u][0] + dp1[u][1] + a[u];
      int d22 = dp2[v][0];
      int d11 = dp1[v][0] + a[v];
      dp2[u].remove(d21);
      dp2[u].remove(d22);
      dp1[u].remove(d11);
      dp2[u].insert(dp1[u][0] + dp1[u][1] + a[u]);
      ans = max(ans, dp2[u][0] + dp2[v][0]);
      dp2[v].remove(dp1[v][0] + dp1[v][1] + a[v]);
      dp1[v].insert(dp1[u][0] + a[u]);
      dp2[v].insert(dp1[v][0] + dp1[v][1] + a[v]);
      dfs(v);
      dp2[u].remove(dp1[u][0] + dp1[u][1] + a[u]);
      dp1[u].insert(d11);
      dp2[u].insert(d21);
      dp2[u].insert(d22);
    }
  };
  dfs(1);
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
