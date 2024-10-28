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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, pair<int, int>>> e;
  vector<vector<int>> mp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      e.emplace_back(x, make_pair(i, j));
      mp[i][j] = x;
    }
  }
  sort(e.begin(), e.end());
  vector<int> fa(n + 1);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  function<int(int)> find = [&](int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
  };
  auto merge = [&](int u, int v) {
    fa[find(u)] = find(v);
  };
  int ans = 0;
  vector<int> b(n + 1);
  for (auto [w, edge] : e) {
    auto [u, v] = edge;
    if (find(u) == find(v)) {
      continue;
    }
    ans += w;
    merge(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    int mi = 1e9;
    for (int j = 1; j <= n; ++j) {
      mi = min(mi, mp[i][j]);
    }
    ans += (a[i] - 1) * mi;
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
