#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

constexpr int MAXN = 5e5 + 10;

void solve() {
  int q;
  cin >> q;
  vector<pair<int, pair<int, int>>> qs(q);
  for (int i = 0; i < q; ++i) {
    int op;
    cin >> op;
    int x = 0, y = 0;
    if (op == 1) {
      cin >> x;
    } else {
      cin >> x >> y;
    }
    qs[i] = {
      op, {x, y}
    };
  }
  reverse(qs.begin(), qs.end());
  deque<int> a;
  vector<int> fa(MAXN);
  for (int i = 1; i < MAXN; ++i) {
    fa[i] = i;
  }
  function<int(int)> find = [&](int u) {
    return fa[u] == u ? u : find(fa[u]);
  };
  auto merge = [&](int u, int v) {
    fa[find(u)] = find(v);
  };

  for (auto [op, in] : qs) {
    auto [x, y] = in;
    if (op == 1) {
      a.push_back(fa[x]);
    } else {
      fa[x] = fa[y];
    }
  }
  reverse(a.begin(), a.end());
  for (auto i : a) {
    cout << i << ' ';
  }
  cout << endl;
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

  return 0;
}
