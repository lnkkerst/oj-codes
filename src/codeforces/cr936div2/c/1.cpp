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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  int l = 0, r = 1e9;
  for (int qwq = 1; qwq <= 50; ++qwq) {
    int x = (l + r + 1) / 2;
    int cut = 0;
    function<int(int, int)> dfs = [&](int u, int pre) -> int {
      int cnt = 1;
      for (auto v : e[u]) {
        if (v == pre) {
          continue;
        }
        cnt += dfs(v, u);
      }
      if (cut < k) {
        if (cnt >= x) {
          ++cut;
          return 0;
        }
      }
      return cnt;
    };
    int c1 = dfs(1, 0);
    if (cut >= k && c1 >= x) {
      l = x;
    } else {
      r = x - 1;
    }
  }
  cout << l << endl;
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
