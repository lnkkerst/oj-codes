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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> qe;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    qe.emplace_back(u, v);
  }
  vector<int> fa;
  vector<int> sz;
  auto init = [&](int n) {
    fa = sz = vector<int>(n + 1, 1);
    for (int i = 0; i <= n; ++i) {
      fa[i] = i;
    }
  };
  function<int(int)> find = [&](int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
  };
  auto merge = [&](int u, int v) {
    int fu = find(u);
    int fv = find(v);
    if (fu == fv) {
      return;
    }
    sz[fu] += sz[fv];
    fa[fv] = fu;
  };
  init(n);
  sort(qe.begin(), qe.end(),
       [&](const pair<int, int> &x, const pair<int, int> &y) {
         return max(a[x.first], a[x.second]) < max(a[y.first], a[y.second]);
       });
  int ma = 0;
  for (auto [u, v] : qe) {
    if (find(u) != find(v)) {
      ma += sz[find(u)] * sz[find(v)] * max(a[u], a[v]);
      merge(u, v);
    }
  }
  init(n);
  sort(qe.begin(), qe.end(),
       [&](const pair<int, int> &x, const pair<int, int> &y) {
         return min(a[x.first], a[x.second]) > min(a[y.first], a[y.second]);
       });
  int mi = 0;
  for (auto [u, v] : qe) {
    if (find(u) != find(v)) {
      mi += sz[find(u)] * sz[find(v)] * min(a[u], a[v]);
      merge(u, v);
    }
  }
  cout << ma - mi << endl;
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
