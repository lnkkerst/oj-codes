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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> s;
  for (int i = 0; i < (1 << n); ++i) {
    if (!(i & (i >> 1)) && !(i & (i << 1))) {
      s.emplace_back(i, bitset<32>(i).count());
    }
  }
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(s.size() + 1, vector<int>(n * n + 1)));
  auto check = [](int x, int y) {
    return (!(x & y) && !(x & (y << 1)) && !((x << 1) & y));
  };
  for (int j = 0; j < s.size(); ++j) {
    dp[1][j][s[j].second] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      for (int x = 0; x < s.size(); ++x) {
        if (!check(s[j].first, s[x].first)) {
          continue;
        }
        for (int l = s[j].second; l <= k; ++l) {
          dp[i][j][l] += dp[i - 1][x][l - s[j].second];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    ans += dp[n][i][k];
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
