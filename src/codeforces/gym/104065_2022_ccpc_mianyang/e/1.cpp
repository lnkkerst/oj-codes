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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n + 1);
  vector<int> sum(n + 1);
  vector<vector<pair<int, int>>> e(n + 1);
  vector<int> p(q + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end(),
         [](const pair<int, int> a, const pair<int, int> b) {
           return a.second < b.second;
         });
  }
  for (int i = 1; i <= q; ++i) {
    cin >> p[i];
  }
  vector<int> dp(n + 1);

  for (int i = q; i >= 1; --i) {}
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
