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
  string s;
  cin >> s;
  s = " " + s;
  vector<vector<int>> e(n + 1);
  vector<int> fa(n + 1), last(n + 1), ans(n + 1);
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    fa[i] = x;
    e[x].emplace_back(i);
  }
  function<void(int)> dfs = [&](int u) {
    last[u] = last[fa[u]];
    if (s[u] == '(') {
      last[u] = u;
    } else if (last[u]) {
      ans[u] = ans[fa[last[u]]] + 1;
      last[u] = last[fa[last[u]]];
    }
    for (auto v : e[u]) {
      dfs(v);
    }
  };
  dfs(1);
  int ansa = ans[1];
  for (int i = 2; i <= n; ++i) {
    ansa ^= i * (ans[i] += ans[fa[i]]);
  }
  cout << ansa << endl;
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
