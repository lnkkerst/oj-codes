#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  vector<int> f(n + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = rand();
  }
  vector<array<int, 4>> d(m + 1);
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      d[j][a[i][j] - 'A'] += f[i];
    }
    tot += f[i];
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    int dis = 0;
    for (int j = 1; j <= m; ++j) {
      for (int c = 0; c < 4; ++c) {
        if (c == a[i][j] - 'A') {
          continue;
        }
        dis += d[j][c];
      }
    }
    if (dis == (tot - f[i]) * k) {
      ans.emplace_back(i);
    }
  }
  auto check = [&](int x) {
    for (int i = 1; i <= n; ++i) {
      if (x == i) {
        continue;
      }
      int cnt = 0;
      for (int j = 1; j <= m; ++j) {
        if (a[i][j] != a[x][j]) {
          ++cnt;
        }
      }
      if (cnt != k) {
        return false;
      }
    }
    return true;
  };
  for (int i = 0; i < ans.size(); ++i) {
    if (check(ans[i])) {
      cout << ans[i] << endl;
      return;
    }
  }
}

signed main() {
  srand(time(nullptr));
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
