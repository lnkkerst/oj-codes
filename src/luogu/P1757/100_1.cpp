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
  int m, n;
  cin >> m >> n;
  unordered_map<int, vector<pair<int, int>>> a;
  for (int i = 1; i <= n; ++i) {
    int w, v, k;
    cin >> w >> v >> k;
    a[k].emplace_back(w, v);
  }
  vector<int> dp(m + 1);
  for (auto &[_, vs] : a) {
    for (int i = m; i >= 0; --i) {
      for (auto &[w, v] : vs) {
        if (i >= w) {
          dp[i] = max(dp[i], dp[i - w] + v);
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
  // cin >> t;
  while (t--) {
    solve();
  }
}
