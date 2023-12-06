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

struct Node {
  multiset<int> data;
  int operator[](int index) {
    if (index >= data.size()) {
      return -1;
    }
    ++index;
    auto it = data.end();
    while (index--) {
      --it;
    }
    return *it;
  }
  auto insert(int x) { return data.insert(x); }
  auto erase(int x) { return data.erase(x); }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> e(n + 1);
  vector<int> b(n + 1);
  vector<int> dis(n + 1, -1);
  vector<Node> diss(n + 1);
  for (int i = 1; i <= k; ++i) {
    int u;
    cin >> u;
    b[u] = 1;
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  function<void(int, int)> dfs0 = [&](int u, int pre) {
    for (int i = 1; i <= 4; ++i) {
      diss[u].insert(-1);
    }
    if (b[u]) {
      dis[u] = 0;
      diss[u].insert(0);
    }
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs0(v, u);
      if (dis[v] != -1) {
        dis[u] = max(dis[u], dis[v] + 1);
        diss[u].insert(dis[v] + 1);
      }
    }
  };
  dfs0(1, 0);
  function<void(int, int)> dfs = [&](int u, int pre) {
    // cout << u << ' ' << dis[u] << ' ' << diss[pre][0] << ' ' << diss[pre][1]
    //      << endl;
    if (dis[u] != -1 && dis[u] + 1 == diss[pre][0]) {
      if (diss[pre][1] != -1) {
        dis[u] = max(dis[u], diss[pre][1] + 1);
        diss[u].insert(diss[pre][1] + 1);
      }
    } else {
      if (dis[pre] != -1) {
        dis[u] = max(dis[u], dis[pre] + 1);
        diss[u].insert(diss[pre][0] + 1);
      }
    }
    // cout << dis[u] << endl;
    for (auto v : e[u]) {
      if (v != pre) {
        dfs(v, u);
      }
    }
  };
  dfs(1, 0);
  // for (int i = 1; i <= n; ++i) {
  //   cout << dis[i] << ' ';
  // }
  cout << *min_element(dis.begin() + 1, dis.end()) << endl;
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
