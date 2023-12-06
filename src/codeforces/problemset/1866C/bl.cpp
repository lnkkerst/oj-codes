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

constexpr int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> e(n + 1);
  for (int u = 1; u <= n; ++u) {
    int s;
    cin >> s;
    for (int i = 1; i <= s; ++i) {
      int v, w;
      cin >> v >> w;
      e[u].emplace_back(v, w);
    }
  }
  vector<int> z;
  function<void(int)> dfs = [&](int u) {
    for (auto [v, w] : e[u]) {
      z.emplace_back(w);
      dfs(v);
    }
  };
  dfs(1);
  int ans = 0;
  for (int i = 0; i < z.size(); ++i) {
    for (int j = i + 1; j < z.size(); ++j) {
      if (z[i] > z[j]) {
        ++ans;
        ans %= MOD;
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
