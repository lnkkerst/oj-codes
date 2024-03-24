#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ae(m + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    ae[i] = {u, v};
  }
  multiset<int> ans;
  int l = 0, r = m;
  for (int qwq = 1; qwq <= 1; ++qwq) {
    // int m = (l + r + 1) / 2;
    vector<vector<pair<int, int>>> e(n + 1);
    for (int i = 1; i <= m; ++i) {
      auto [u, v] = ae[i];
      e[u].emplace_back(v, i);
      e[v].emplace_back(u, i);
    }
    vector<int> inq(n + 1);
    vector<int> vis(n + 1);
    multiset<int> s;
    vector<decltype(s)> qs;
    multiset<int> ms = {(int)1e9};
    function<void(int, int)> dfs = [&](int u, int pre) {
      for (auto i : s) {
        cout << i << ' ';
      }
      cout << endl;
      if (!s.empty() && *s.rbegin() > *ms.rbegin()) {
        return;
      }
      if (inq[u]) {
        auto itm = ms.rbegin();
        auto it = s.rbegin();
        while (itm != ms.rend() && it != s.rend()) {
          if (*itm < *it) {
            break;
          }
          if (*itm > *it) {
            ms = s;
            break;
          }
          ++itm;
          ++it;
        }
        if (it == s.rend()) {
          ms = s;
        }
        return;
      }
      inq[u] = true;
      vis[u] = true;
      for (auto [v, x] : e[u]) {
        if (v == pre) {
          continue;
        }
        s.insert(x);
        dfs(v, u);
        s.erase(s.lower_bound(x));
      }
      inq[u] = false;
    };
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        dfs(i, 0);
      }
    }
    if (*ms.begin() == (int)1e9) {
      l = m + 1;
    } else {
      ans = ms;
      r = m;
    }
  }
  if (ans.empty()) {
    cout << -1 << endl;
    return;
  }
  bool fl = false;
  for (auto i : ans) {
    if (fl) {
      cout << ' ';
    }
    cout << i;
    fl = true;
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

  return 0;
}
