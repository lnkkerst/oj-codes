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
  int k, n;
  cin >> k >> n;
  vector<int> t(n), w(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> w[i];
  }
  vector<int> st((1 << n) + 10, -1), sw((1 << n) + 10, -1);
  auto get_t = [&](int s) {
    if (st[s] != -1) {
      return st[s];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if ((s >> i) & 1) {
        res = max(res, t[i]);
      }
    }
    return st[s] = res;
  };
  auto get_w = [&](int s) {
    if (sw[s] != -1) {
      return sw[s];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if ((s >> i) & 1) {
        res += w[i];
      }
    }
    return sw[s] = res;
  };
  vector<int> dp((1 << n) + 10, 1e9);
  dp[0] = 0;

  for (int i = 0; i < (1 << n); ++i) {
    for (int j = i; j; j = (j - 1) & i) {
      // j 为 i 的子集
    }
  }
  for (int i = 0; i < (1ll << n); ++i) {
    for (int j = i; j; j = (j - 1) & i) {
      if (get_w(j) <= k) {
        dp[i] = min(dp[i], get_t(j) + dp[i ^ j]);
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
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
