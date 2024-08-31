#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    e[v].emplace_back(u);
  }
  int k;
  cin >> k;
  vector<int> p(k);
  for (auto &i : p) {
    cin >> i;
  }
  vector<int> dis(n + 1, INT_MAX);
  vector<set<int>> s(n + 1);
  auto bfs = [&](int st) {
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (auto v : e[u]) {
        // cout << v << ' ' << dis[v] << endl;
        if (dis[v] == INT_MAX) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
        if (dis[v] == dis[u] + 1) {
          s[v].insert(u);
        }
      }
    }
  };
  bfs(p.back());
  // for (int i = 1; i <= n; ++i) {
  //   cout << i << ": ";
  //   for (auto x : s[i]) {
  //     cout << x << ' ';
  //   }
  //   cout << endl;
  // }
  int mi = 0, ma = 0;
  for (int i = 0; i < k - 1; ++i) {
    if (s[p[i]].find(p[i + 1]) != s[p[i]].end()) {
      if (s[p[i]].size() > 1) {
        ++ma;
      }
    } else {
      ++mi;
      ++ma;
    }
  }
  cout << mi << ' ' << ma << endl;
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
