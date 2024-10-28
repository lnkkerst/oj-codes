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
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  vector<vector<int>> dp(n + 10, vector<int>(m + 10, 1e9));
  vector<vector<int>> dis(n + 10, vector<int>(n + 10));
  for (int i = 1; i <= n; ++i) {
    int mid = i;
    for (int j = i + 1; j <= n; ++j) {
      dis[i][j] = dis[i][j - 1];
      if ((i + j) & 1) {
        ++mid;
        dis[i][j] += a[mid] - a[mid - 1];
      }
      dis[i][j] += a[j] - a[mid];
    }
  }
  dp[0][0] = 0;
  vector<vector<int>> w(n + 10, vector<int>(m + 10));
  for (int i = 1; i <= n; ++i) {
    w[i][min(m, i) + 1] = i;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = min(i, m); j >= 1; --j) {
      for (int k = w[i - 1][j]; k <= w[i][j + 1]; ++k) {
        if (dp[k][j - 1] + dis[k + 1][i] < dp[i][j]) {
          dp[i][j] = dp[k][j - 1] + dis[k + 1][i];
          w[i][j] = k;
        }
      }
    }
  }
  cout << dp[n][m] << endl;
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
