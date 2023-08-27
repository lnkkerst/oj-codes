#pragma GCC optimize(2)
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> e(n + 1);
  vector<int> h(n + 1), mh(n + 1);
  vector<int> d(n + 1), inq(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
    ++d[u];
    ++d[v];
  }
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (d[i] <= 1) {
      q.push(i);
      inq[i] = true;
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    int sz = q.size();
    for (int j = 1; j <= sz; ++j) {
      int u = q.front();
      q.pop();
      ++ans;
      for (auto v : e[u]) {
        if (inq[v]) {
          continue;
        }
        --d[v];
        if (d[v] <= 1) {
          q.push(v);
          inq[v] = true;
        }
      }
    }
  }
  cout << n - ans << endl;
  return;
  function<void(int, int)> dfs = [&](int u, int p) {
    if (u != 1 && e[u].size() == 1) {
      h[u] = 1;
      mh[u] = 1;
      return;
    }
    for (auto v : e[u]) {
      if (v == p) {
        continue;
      }
    }
  };
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
