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

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    auto &[x, y] = a[i];
    cin >> x >> y;
  }
  int l = 0, r = 1e9;
  for (int qwq = 1; qwq <= 100; ++qwq) {
    int mid = (l + r + 1) / 2;
    int tot = 0;
    vector<int> dp(n + 1);
    int ma = 0;
    for (int i = 1; i <= n; ++i) {
      auto &[x, y] = a[i];
      if (x >= mid) {
        ++tot;
      }
      int t = 0;
      if (x < mid && y >= mid) {
        t = 1;
      }
      if (x >= mid && y < mid) {
        t = -1;
      }
      dp[i] = t;
      dp[i] = max(dp[i], dp[i - 1] + t);
      ma = max(ma, dp[i]);
    }
    if (tot + ma >= (n + 1) / 2) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
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
