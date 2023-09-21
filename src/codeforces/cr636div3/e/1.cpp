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
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> p(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> p[i];
  }
  sort(p.begin() + 1, p.begin() + 1 + m);
  for (int i = 2; i <= m; ++i) {
    p[i] += p[i - 1];
  }
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  auto bfs = [&](int s, vector<int> &d) {
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : e[u]) {
        if (d[v] > d[u] + 1) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
  };
  vector<int> da(n + 1, 1e9), db = da, dc = da;
  bfs(a, da);
  bfs(b, db);
  bfs(c, dc);
  int ans = 2e18;
  for (int i = 1; i <= n; ++i) {
    if (da[i] + db[i] + dc[i] > m) {
      continue;
    }
    ans = min(ans, p[db[i]] + p[db[i] + da[i] + dc[i]]);
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
