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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    e[u][v] = e[v][u] = 1;
  }
  vector<vector<int>> connected;
  vector<int> cur;
  vector<int> vis(n + 1);
  function<void(int)> dfs = [&](int u) {
    if (vis[u]) {
      return;
    }
    vis[u] = true;
    cur.emplace_back(u);
    for (int i = 1; i <= n; ++i) {
      if (e[u][i]) {
        dfs(i);
      }
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i);
    }
    if (!cur.empty()) {
      connected.emplace_back(cur);
    }
    cur.clear();
  }
  int cnt = 0;
  auto judge = [&](const vector<int> &nodes) {
    for (auto u : nodes) {
      for (auto v : nodes) {
        if (u == v) {
          continue;
        }
        if (!e[u][v]) {
          return false;
        }
      }
    }
    return true;
  };
  for (auto &a : connected) {
    int n = a.size();
    if ((n % 4 == 0) || ((n + 1) % 4) == 0) {
      if (judge(a)) {
        ++cnt;
      }
    }
  }
  if ((cnt + n + m) % 2 == 1) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
