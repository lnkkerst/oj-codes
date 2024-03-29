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

#define int long long

void solve() {
  int n;
  cin >> n;
  map<int, int> b;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++b[x];
  }
  vector<int> dp(n + 1, 1e9);
  int m = 0;
  while (b[m]) {
    ++m;
  }
  dp[m] = 0;
  for (int i = m; i >= 1; --i) {
    for (int j = 0; j < i; ++j) {
      dp[j] = min(dp[j], dp[i] + i * b[j]);
    }
  }
  cout << dp[0] - m << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
