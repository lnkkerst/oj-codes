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
  vector<string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  int ans = 0;
  vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pre[i][j] = pre[i][j - 1] + (a[i][j] == '*' ? 1 : 2);
      // cout << pre[i][j] << ' ';
    }
    // cout << endl;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] != '*') {
        continue;
      }
      for (int k = i + 1, c = 1; k <= n; ++k, ++c) {
        if (j - c < 1 || j + c > m) {
          break;
        }
        int l = j - c, r = j + c;
        if (a[k][l] != '*' || a[k][r] != '*') {
          break;
        }
        if (pre[k][r] - pre[k][l - 1] == (r - l + 1)) {
          ++ans;
        }
      }
    }
  }
  cout << ans << endl;
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
