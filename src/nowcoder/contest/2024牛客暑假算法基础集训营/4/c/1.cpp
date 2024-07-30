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
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x != i) {
      b[i] = true;
      e[x].emplace_back(i);
      e[i].emplace_back(x);
    }
  }
  vector<int> vis(n + 1);
  int cnt;
  function<void(int, int)> dfs = [&](int u, int pre) {
    if (vis[u]) {
      return;
    }
    vis[u] = true;
    ++cnt;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
    }
  };
  int ans = 0;
  int c2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      continue;
    }
    cnt = 0;
    dfs(i, 0);
    // cout << i << ' ' << cnt << endl;
    ans += cnt / 3;
    c2 += cnt % 3 == 2;
  }
  cout << ans + (c2 + 1) / 2 << endl;
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
