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
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int> fa(n + 1);
  vector<int> sg(n + 1);
  for (int i = 1; i <= n; ++i) {
    int u;
    cin >> u;
    fa[i] = u;
    e[u].emplace_back(i);
  }
  function<void(int)> dfs = [&](int u) {
    for (auto v : e[u]) {
      dfs(v);
      sg[u] ^= sg[v] + 1;
    }
  };
  dfs(0);
  cout << (sg[0] ? "YES" : "NO") << endl;
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
