#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
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

constexpr int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n + 1, vector<int>(n + 1, INT64_MAX / 2));
  for (int k = 1; k <= m; ++k) {
    int l1, r1, l2, r2, a, b;
    cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
    int w = a << b;
    for (int i = l1; i <= r1; ++i) {
      for (int j = l2; j <= r2; ++j) {
        e[i][j] = min(e[i][j], w);
      }
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (e[1][i] == INT64_MAX / 2 || e[i][1] == INT64_MAX / 2) {
      cout << -1 << ' ';
    } else {
      cout << (e[1][i] % MOD + e[i][1] % MOD) % MOD << ' ';
    }
  }
  cout << endl;
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
