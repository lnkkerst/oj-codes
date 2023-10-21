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
  vector<vector<int>> e(n + 1);
  vector<int> a(n + 1);
  vector<int> fa(n + 1);
  vector<int> su(n + 1);
  vector<int> pre(n + 1);
  vector<int> pre2(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  int ans1 = 0;
  int mau = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    su[u] = a[u];
    for (auto v : e[u]) {
      if (v == fa) {
        continue;
      }
      dfs(v, u);
      if (su[u] + su[v] > ans1) {
        ans1 = su[u] + su[v];
        mau = u;
      }
      if (su[v] + a[u]) {
      }
      su[u] = max(su[u], su[v] + a[u]);
    }
    ans1 = max(ans1, su[u]);
  };
  dfs(1, 0);
  cout << ans1 << endl;
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
