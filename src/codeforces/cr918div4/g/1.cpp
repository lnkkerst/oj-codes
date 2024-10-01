#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
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

constexpr int INF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> e(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  vector<int> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  vector<vector<int>> dis(n + 1, vector<int>(1001, INF));
  vector<vector<int>> vis(n + 1, vector<int>(1001));
  using piii = pair<int, pair<int, int>>;
  priority_queue<piii, vector<piii>, greater<>> q;
  dis[1][s[1]] = 0;
  q.push({
    0, {1, s[1]}
  });
  while (!q.empty()) {
    auto [u, k] = q.top().second;
    q.pop();
    if (vis[u][k] || dis[u][k] == INF) {
      continue;
    }
    vis[u][k] = true;
    for (auto [v, w] : e[u]) {
      int mi = min(s[v], k);
      if (dis[v][mi] > dis[u][k] + w * k) {
        dis[v][mi] = dis[u][k] + w * k;
        q.push({
          dis[v][mi], {v, mi}
        });
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= 1000; ++i) {
    ans = min(ans, dis[n][i]);
  }
  cout << ans << endl;
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
