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
  int n, m;
  cin >> m >> n;
  vector<vector<int>> e(n + 1);
  vector<int> v(n + 1), p(n + 1), f(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> p[i] >> f[i];
    if (f[i]) {
      e[f[i]].emplace_back(i);
    }
  }
  vector<int> dp(m + 1);
  for (int i = 1; i <= n; ++i) {
    if (f[i]) {
      continue;
    }
    for (int j = m; j >= 0; --j) {
      for (int k = 0; k < (1ll << e[i].size()); ++k) {
        int cw = v[i];
        int cv = v[i] * p[i];

        for (int l = 0; l < e[i].size(); ++l) {
          if ((k >> l) & 1) {
            cw += v[e[i][l]];
            cv += v[e[i][l]] * p[e[i][l]];
          }
        }
        if (j >= cw) {
          dp[j] = max(dp[j], dp[j - cw] + cv);
        }
      }
    }
  }
  cout << *max_element(dp.begin() + 1, dp.end());
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
