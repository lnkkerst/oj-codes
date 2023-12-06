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
  int n;
  cin >> n;
  deque<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int last = a[1] + 1;
  deque<deque<int>> aa;
  deque<int> cur;
  for (int i = 1; i <= n; ++i) {
    // cout << a[i] << ' ' << last << endl;
    // cout << a[i] % 2 << ' ' << last % 2 << endl;
    if ((a[i] % 2 + 2) % 2 != (last % 2 + 2) % 2) {
      cur.emplace_back(a[i]);
      last = a[i];
    } else {
      aa.emplace_back(cur);
      cur.clear();
      cur.emplace_back(a[i]);
      last = a[i];
    }
  }
  if (!cur.empty()) {
    aa.emplace_back(cur);
  }
  int ans = -2e9;
  for (auto x : aa) {
    // for (auto i : x) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    int m = x.size();
    deque<int> dp(x.size() + 1);
    x.push_front(0);
    dp[1] = x[1];
    // cout << "x1 " << x[1] << endl;
    for (int i = 2; i <= m; ++i) {
      dp[i] = x[i];
      if (dp[i - 1] > 0) {
        dp[i] += dp[i - 1];
      }
    }
    ans = max(ans, *max_element(dp.begin() + 1, dp.end()));
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
