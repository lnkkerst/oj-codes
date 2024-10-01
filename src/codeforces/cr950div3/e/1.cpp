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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  auto b = a;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> b[i][j];
    }
  }
  vector<int> f(n * m * 2 + 1);
  for (int i = 1; i <= n * m * 2; ++i) {
    f[i] = i;
  }
  function<int(int)> find = [&](int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
  };
  auto merge = [&](int u, int v) {
    f[find(u)] = find(v);
  };
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      merge(a[i][j], a[i][1]);
      merge(a[i][j] + n * m, a[1][j] + n * m);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (find(b[i][j]) != find(b[i][1])
          || find(b[i][j] + n * m) != find(b[1][j] + n * m)) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
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
