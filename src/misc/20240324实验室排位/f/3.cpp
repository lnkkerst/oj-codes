
#pragma GCC optimize(2)
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  // cin >> n >> m;
  vector<pair<int, int>> ae(m + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    // cin >> u >> v;
    ae[i] = {u, v};
  }
  int l = 0, r = m;
  bool fla = false;
  for (int qwq = 1; qwq <= 20; ++qwq) {
    int m = (l + r) / 2;
    vector<vector<pair<int, int>>> e(n + 1);
    for (int i = 1; i <= m; ++i) {
      auto [u, v] = ae[i];
      e[u].emplace_back(v, i);
      e[v].emplace_back(u, i);
    }
    vector<int> vis(n + 1);
    bool fl = false;
    function<void(int, int)> dfs = [&](int u, int pre) {
      if (fl) {
        return;
      }
      if (vis[u]) {
        fl = true;
        return;
      }
      vis[u] = true;
      for (auto [v, x] : e[u]) {
        if (v == pre) {
          continue;
        }
        dfs(v, u);
      }
    };
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        dfs(i, 0);
      }
    }
    if (!fl) {
      l = m + 1;
    } else {
      fla = true;
      r = m;
    }
  }
  if (!fla) {
    puts("-1");
    return;
  }
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 1; i <= r; ++i) {
    auto [u, v] = ae[i];
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  deque<int> q;
  vector<int> vis(n + 1);
  vector<int> s;
  s.reserve(2e5);
  decltype(s) ms;
  function<void(int, int)> dfs = [&](int u, int pre) {
    if (!ms.empty()) {
      return;
    }
    if (vis[u]) {
      ms = s;
      return;
    }
    vis[u] = true;
    for (auto [v, x] : e[u]) {
      if (v == pre) {
        continue;
      }
      s.push_back(x);
      dfs(v, u);
      s.pop_back();
    }
  };
  dfs(ae[r].first, 0);
  sort(ms.begin(), ms.end());
  bool flc = false;
  for (auto i : ms) {
    if (flc) {
      putchar(' ');
    }
    printf("%d", i);
    // cout << i;
    flc = true;
  }
  puts("");
  // cout << endl;
}

signed main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}
