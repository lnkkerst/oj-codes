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

#define int long long

void solve() {
  int n;
  cin >> n;
  map<int, int, greater<>> mp;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++mp[x];
  }
  n = 1e5;
  vector<int> dp(n + 1);
  dp[1] = mp[1];
  for (int i = 2; i <= n; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + i * mp[i]);
  }
  cout << dp[n] << endl;
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
