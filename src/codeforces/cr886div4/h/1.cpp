#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> e(n + 1);
  vector<int> vis(n + 1, 0);
  vector<int> coor(n + 1, 0);
  vector<array<int, 3>> inp;
  for (int i = 1; i <= m; ++i) {
    int a, b, d;
    cin >> a >> b >> d;
    e[a].emplace_back(b, d);
    e[b].emplace_back(a, -d);
    inp.push_back({a, b, d});
  }
  function<void(int, int)> dfs = [&](int u, int w) {
    if (vis[u]) {
      return;
    }
    vis[u] = true;
    coor[u] = w;
    for (auto &i : e[u]) {
      dfs(i.first, coor[u] + i.second);
    }
  };
  for (int i = 1; i <= n; ++i) {
    dfs(i, coor[i]);
  }
  for (auto &i : inp) {
    if (coor[i[0]] + i[2] != coor[i[1]]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
