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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> b(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].first >> b[i].second;
  }
  vector<int> s(m + 1);
  int ans = 1e9;
  auto ba = a;
  auto bs = s;
  function<void(vector<int> s, int st)> dfs = [&](vector<int> s, int st) {
    if (st == m + 1) {
      auto na = a;
      for (int i = 1; i <= m; ++i) {
        if (s[i] == 0) {
          na[b[i].first] += 3;
        } else if (s[i] == 1) {
          na[b[i].second] += 3;
        } else {
          na[b[i].first] += 1;
          na[b[i].second] += 1;
        }
      }
      auto bna = na;
      int sc = na[1];
      sort(na.begin() + 1, na.begin() + n + 1, greater<>());
      int rk =
          (lower_bound(na.begin() + 1, na.begin() + n + 1, sc, greater<>()) -
           na.begin());
      if (rk < ans) {
        ans = rk;
        ba = bna;
        bs = s;
      }
      ans = min(ans, rk);
      return;
    }
    s[st] = 0;
    dfs(s, st + 1);
    s[st] = 1;
    dfs(s, st + 1);
    s[st] = 2;
    dfs(s, st + 1);
  };
  dfs(s, 1);
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
