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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  int p, q;
  cin >> p >> q;
  vector<pair<int, int>> op(q);
  for (auto &[x, y] : op) {
    cin >> x >> y;
  }
  auto trans = [&](int tp, int id) {
    if (tp == 1) {
      auto ba = a[id][m];
      for (int i = m; i >= 2; --i) {
        a[id][i] = a[id][i - 1];
      }
      a[id][1] = ba;
    } else {
      auto ba = a[n][id];
      for (int i = n; i >= 2; --i) {
        a[i][id] = a[i - 1][id];
      }
      a[1][id] = ba;
    }
  };
  while (p--) {
    for (auto [x, y] : op) {
      trans(x, y);
      // for (int i = 1; i <= n; ++i) {
      //   for (int j = 1; j <= m; ++j) {
      //     cout << a[i][j];
      //   }
      //   cout << endl;
      // }
      // cout << endl;
    }
  }
  cout << a[x][y] << endl;
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
