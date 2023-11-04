#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  vector<int> a(m), b(m);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  vector<vector<int>> e(n + 1);
  for (int i = 0; i < m; ++i) {
    e[a[i]].emplace_back(b[i]);
    e[b[i]].emplace_back(a[i]);
  }
  vector<int> vis(n + 1);
  vector<int> val(n + 1);
  function<void(int, int)> dfs = [&](int u, int fa) {
    if (vis[u]) {
      if (!(val[fa] ^ val[u])) {
        cout << "No" << endl;
        exit(0);
      }
      return;
    }
    vis[u] = true;
    val[u] = !val[fa];
    for (auto v : e[u]) {
      if (v == fa) {
        continue;
      }
      dfs(v, u);
    }
  };
  val[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  cout << "Yes" << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
