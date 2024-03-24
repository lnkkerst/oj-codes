#pragma GCC optimize(2)
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ae(m + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    ae[i] = {u, v};
  }
  int l = 0, r = m;
  bool fla = false;
  vector<int> fa(n + 1);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  function<int(int)> find = [&](int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
  };
  auto merge = [&](int u, int v) {
    fa[find(u)] = find(v);
  };

  for (int i = 1; i <= m; ++i) {
    auto [u, v] = ae[i];
    int fu = find(u);
    int fv = find(v);
    if (fu == fv) {
      r = i;
      fla = true;
      break;
    }
    merge(u, v);
  }

  for (int qwq = 1; qwq <= 0; ++qwq) {
    int m = (l + r) / 2;
    vector<vector<pair<int, int>>> e(n + 1);
    for (int i = 1; i <= m; ++i) {
      auto [u, v] = ae[i];
      e[u].emplace_back(v, i);
      e[v].emplace_back(u, i);
    }
    vector<int> vis(n + 1);
    bool fl = false;
    auto bfs = [&](int s) {
      queue<pair<int, int>> q;
      q.push({s, 0});
      vis[s] = true;
      while (!fl && !q.empty()) {
        auto [u, pre] = q.front();
        q.pop();
        for (auto [v, x] : e[u]) {
          if (v == pre) {
            continue;
          }
          if (vis[v]) {
            fl = true;
            break;
          }
          vis[v] = true;
          q.push({v, u});
        }
      }
    };
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
        bfs(i);
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
    cout << -1 << endl;
    return;
  }
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 1; i <= r; ++i) {
    auto [u, v] = ae[i];
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  vector<int> vis(n + 1);
  vector<int> s;
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
      cout << ' ';
    }
    cout << i;
    flc = true;
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

  return 0;
}
