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
  vector<set<int>> e(n + 1);
  for (int i = 1; i <= n; ++i) {
    int l, r;
    cin >> l >> r;
    e[l - 1].insert(r);
    e[r].insert(l - 1);
  }
  vector<int> vis(n + 1);
  bool fl = true;
  function<void(int, int)> dfs = [&](int u, int pre) {
    if (!fl) {
      return;
    }
    if (vis[u]) {
      fl = false;
      return;
    }
    vis[u] = true;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
    }
  };
  dfs(0, -1);
  for (int i = 0; i <= n; ++i) {
    if (!vis[i]) {
      fl = false;
      break;
    }
  }
  cout << fl << endl;
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
