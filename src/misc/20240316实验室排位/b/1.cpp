#pragma GCC optimize(2)
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> lan(m + 1);
  bool fl = true;
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    if (k) {
      fl = false;
    }
    for (int j = 1; j <= k; ++j) {
      int x;
      cin >> x;
      lan[x].emplace_back(i);
    }
  }
  if (fl) {
    cout << n << endl;
    return 0;
  }
  vector<int> f(n + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
  }

  function<int(int)> find = [&](int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
  };

  auto merge = [&](int u, int v) {
    f[find(u)] = find(v);
  };

  for (int i = 1; i <= m; ++i) {
    if (lan[i].empty()) {
      continue;
    }

    for (auto x : lan[i]) {
      merge(lan[i][0], x);
    }
  }

  set<int> b;
  for (int i = 1; i <= n; ++i) {
    b.insert(find(i));
  }
  cout << b.size() - 1 << endl;
}
