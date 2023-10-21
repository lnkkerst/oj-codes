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

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int> a(n + 1);
  vector<int> fa(n + 1);
  vector<int> su(n + 1);
  vector<int> pre(n + 1);
  vector<int> pre2(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  function<void(int)> dfs1 = [&](int u) {
    auto ne = vector<int>();
    for (auto v : e[u]) {
      if (v != fa[u]) {
        ne.emplace_back(v);
      }
    }
    e[u] = ne;
    for (auto v : e[u]) {
      fa[v] = u;
      dfs1(v);
    }
  };
  dfs1(1);
  int mau = 0;
  int maa = 0;
  function<void(int)> dfs2 = [&](int u) {
    if (e[u].empty()) {
      su[u] = a[u];
      return;
    }
    su[u] = 0;
    vector<pair<int, int>> ssu;
    for (auto v : e[u]) {
      dfs2(v);
      if (su[v] <= 0) {
        continue;
      }
      ssu.emplace_back(su[v], v);
    }
    if (!ssu.empty()) {
      auto ma = max_element(ssu.begin(), ssu.end());
      pre[u] = ma->second;
      ssu.erase(ma);
    }
    if (!ssu.empty()) {
      pre2[u] = max_element(ssu.begin(), ssu.end())->second;
    }
    su[u] = a[u];
    if (pre[u]) {
      su[u] += su[pre[u]];
    }
    int t = su[u];
    if (pre2[u]) {
      t += su[pre2[u]];
    }
    if (t > maa) {
      mau = u;
      maa = t;
    }
  };
  dfs2(1);
  int ans1 = 0;
  function<void(int)> dfs3 = [&](int u) {
    ans1 += a[u];
    a[u] = -a[u];
    if (pre[u]) {
      dfs3(pre[u]);
    }
  };
  ans1 += a[mau];
  a[mau] = -a[mau];
  if (pre[mau]) {
    dfs3(pre[mau]);
  }
  if (pre2[mau]) {
    dfs3(pre2[mau]);
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << a[i] << ' ';
  // }
  // cout << endl;
  mau = 0;
  maa = 0;
  fill(su.begin(), su.end(), 0);
  fill(pre.begin(), pre.end(), 0);
  fill(pre2.begin(), pre2.end(), 0);
  dfs2(1);
  ans1 += a[mau];
  a[mau] = -a[mau];
  if (pre[mau]) {
    dfs3(pre[mau]);
  }
  if (pre2[mau]) {
    dfs3(pre2[mau]);
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << a[i] << ' ';
  // }
  // cout << endl;
  cout << ans1 << endl;
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
