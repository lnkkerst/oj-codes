#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long

using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<vector<pair<int, int>>> e(n + 1);
  vector<int> sz(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  function<void(int, int)> dfs1 = [&](int u, int fa) {
    sz[u] = 0;
    for (auto i : e[u]) {
      auto v = i.first;
      if (v == fa) {
        continue;
      }
      dfs1(v, u);
      sz[u] += sz[v];
    }
    if (sz[u] == 0) {
      sz[u] = 1;
    }
  };
  dfs1(1, 0);
  vector<pair<int, int>> ae;
  function<void(int, int)> dfs2 = [&](int u, int fa) {
    for (auto i : e[u]) {
      int v = i.first;
      if (v == fa) {
        continue;
      }
      ae.emplace_back(i.second, sz[v]);
      dfs2(v, u);
    }
  };
  dfs2(1, 0);
  int tot = 0;
  for (auto i : ae) {
    tot += i.first * i.second;
  }
  auto cmp = [](pair<int, int> a, pair<int, int> b) {
    int na = a.first * a.second - (a.first / 2 * a.second);
    int nb = b.first * b.second - (b.first / 2 * b.second);
    return na < nb;
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
  for (auto i : ae) {
    q.push(i);
  }
  int ans = 0;
  while (tot > s) {
    auto u = q.top();
    q.pop();
    ++ans;
    tot -= u.first * u.second - (u.first / 2 * u.second);
    u.first /= 2;
    q.push(u);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
