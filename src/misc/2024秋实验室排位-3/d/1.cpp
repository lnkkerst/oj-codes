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
  int w;
  cin >> w;
  vector<vector<int>> e(1);
  vector<int> a(1);
  function<void(int, int, int)> add = [&](int fa, int m, int n) {
    int cid = e.size();
    e.emplace_back();
    a.emplace_back();
    e[fa].emplace_back(cid);
    a[cid] = m;

    for (int i = 1; i <= n; ++i) {
      int nm, nn;
      cin >> nm >> nn;
      add(cid, nm, nn);
    }
  };
  int im, in;
  cin >> im >> in;
  add(0, im, in);
  int ans = 0;
  function<void(int, int)> dfs = [&](int u, int pre) {
    vector<int> rv;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      rv.emplace_back(a[v]);
    }
    sort(rv.begin(), rv.end());
    int cnt = 0;
    int tot = 0;
    for (int i = 0; i < rv.size(); ++i) {
      if (tot + rv[i] <= w) {
        ++cnt;
        tot += rv[i];
      }
    }
    // cout << "u: " << a[u] << ' ' << tot << endl;
    ans += rv.size() - cnt;
    a[u] += tot;
    if (a[u]) {
      ans += (a[u] + w - 1) / w - 1;
      a[u] %= w;
      if (a[u] == 0) {
        if (u != 1) {
          ++ans;
        }
      }
    }
  };
  dfs(0, -1);
  cout << ans + 1 << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
