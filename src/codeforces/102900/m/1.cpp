#include <sstream>
#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  map<string, set<string>> e;
  map<string, bool> b;
  map<string, int> sz;
  auto split = [](string &os) {
    vector<string> res;
    istringstream f(os);
    string s;
    while (getline(f, s, '/')) {
      res.emplace_back(s);
    }
    return res;
  };
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    auto as = split(s);
    string fs = "";
    for (const auto &j : as) {
      auto cs = fs + "/" + j;
      e[fs].insert(cs);
      fs = cs;
    }
  }
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    auto as = split(s);
    string fs = "";
    for (const auto &j : as) {
      auto cs = fs + "/" + j;
      e[fs].insert(cs);
      fs = cs;
    }
    b[fs] = true;
  }
  function<void(string)> dfs = [&](string u) {
    if (sz[u] || b[u]) {
      return;
    }
    if (e[u].size() == 0) {
      if (!b[u]) {
        sz[u] = 1;
      }
      return;
    }
    int csz = 0;
    bool fl = false;
    for (auto v : e[u]) {
      dfs(v);
      if (b[v]) {
        fl = true;
      }
      csz += sz[v];
    }
    if (fl) {
      sz[u] = csz;
      b[u] = true;
    } else {
      sz[u] = 1;
    }
  };
  dfs("");
  int ans = 0;
  for (auto v : e[""]) {
    ans += sz[v];
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
