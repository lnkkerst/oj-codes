#pragma GCC optimize(2)
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> e(n + 1);
  vector<int> a(n + 1);
  vector<int> vis(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  bool fl = false;
  int st = 0;
  vector<vector<int>> ans(n + 1);
  function<void(int, int)> dfs = [&](int u, int p) {
    if (fl) {
      return;
    }
    map<int, int> ws;
    for (auto i : e[u]) {
      int v = i.first, w = i.second;
      if (vis[v]) {
        if (a[v] != (p ^ w)) {
          fl = true;
        }
      } else {
        vis[v] = 1;
        a[v] = p ^ w;
        ans[st].emplace_back(v);
        dfs(v, a[v]);
      }
    }
  };
  int ansa = 0;
  for (int i = 1; i <= n; ++i) {
    if (fl) {
      cout << -1 << endl;
      return 0;
    }
    if (!vis[i]) {
      st = i;
      vis[i] = 1;
      dfs(i, 0);
      int t = 0;
      auto &ta = ans[i];
      map<int, int> cnt;
      for (int j = 0; j < 30; ++j) {
        for (auto i : ta) {
          if ((a[i] >> j) & 1) {
            ++cnt[j];
          }
        }
        if (cnt[j] > ta.size() / 2) {
          t += (1 << j);
        }
      }
      int res = t;
      for (auto i : ta) {
        res += a[i] ^ t;
      }
      ansa += res;
    }
  }
  if (fl) {
    cout << -1 << endl;
  } else {
    cout << ansa << endl;
  }
}
