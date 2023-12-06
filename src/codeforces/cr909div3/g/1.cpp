#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

#define endl "\n"

using Tree = tree<int, null_type, less<>, rb_tree_tag,
                  tree_order_statistics_node_update>;
// using Tree = set<int>; // That's OK :)

struct Node {
  int l, r;
  int id;
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> p(n + 1);
  vector<vector<int>> e(n + 1);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  map<int, int> id;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    id[p[i]] = i;
  }
  vector<vector<Node>> qs(n + 1);
  for (int i = 1; i <= q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    qs[x].push_back({l, r, i});
  }
  vector<Tree *> tr(n + 1);
  vector<int> ans(q + 1);
  function<void(int, int)> dfs = [&](int u, int pre) {
    tr[u] = new Tree;
    tr[u]->insert(id[u]);
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      Tree *trn, *trb;
      if (tr[u]->size() > tr[v]->size()) {
        trn = tr[u];
        trb = tr[v];
      } else {
        trn = tr[v];
        trb = tr[u];
      }
      for (auto i : *trb) {
        trn->insert(i);
      }
      tr[u] = trn;
      delete trb;
    }
    for (auto [l, r, id] : qs[u]) {
      auto it = tr[u]->lower_bound(l);
      if (it != tr[u]->end() && *it <= r) {
        ans[id] = 1;
      }
    }
  };
  dfs(1, 0);
  for (int i = 1; i <= q; ++i) {
    cout << (ans[i] ? "YES" : "NO") << endl;
  }
  cout << endl;
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
