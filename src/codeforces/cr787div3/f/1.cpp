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

void solve() {
  int n, k;
  cin >> n >> k;
  int x, y;
  cin >> x >> y;
  vector<int> a(k);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  vector<int> fl1(n + 1), fl2(n + 1);
  for (auto u : a) {
    fl1[u] = true;
  }
  fl2[y] = true;
  function<void(int, int)> dfs = [&](int u, int pre) {
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      if (fl1[v]) {
        fl1[u] = true;
      }
      if (fl2[v]) {
        fl2[u] = true;
      }
    }
  };
  dfs(x, 0);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == x) {
      continue;
    }
    if (fl2[i]) {
      ++ans;
    } else if (fl1[i]) {
      ans += 2;
    }
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
