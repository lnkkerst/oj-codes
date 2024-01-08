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
#define endl "\n"

void solve() {
  int n;
  cin >> n;
  vector<int> fa(n + 1);
  vector<int> a(n + 1);
  vector<vector<int>> e(n + 1);
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    fa[i] = p;
    e[p].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<vector<set<int> *>> b(n + 1);
  int ans = 1;
  function<void(int)> dfs = [&](int u) {
    if (e[u].empty()) {
      auto s = new set<int>();
      s->insert(a[u]);
      b[u].emplace_back(s);
      return;
    }
    vector<int> tm;
    for (auto v : e[u]) {
      dfs(v);
      int ma = 0;
      for (auto i : b[v]) {
        i->insert(a[u]);
        if (i->size() > ma) {
          ma = i->size();
        }
        ans = max(ans, (int)(i->size()));
        b[u].emplace_back(i);
      }
      tm.emplace_back(ma);
      b[v].clear();
    }
    if (tm.size() >= 2) {
      auto it1 = max_element(tm.begin(), tm.end());
      int l = *it1;
      tm.erase(it1);
      auto it2 = max_element(tm.begin(), tm.end());
      ans = max(ans, l * (*it2));
    }
  };
  dfs(1);
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
