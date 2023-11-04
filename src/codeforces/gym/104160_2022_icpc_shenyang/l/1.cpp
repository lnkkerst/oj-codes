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

void solve() {
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> a, b;
  vector<int> hp(n + m), atk(n + m);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    hp[i] = atk[i] = x;
    a.insert({0, i});
  }
  for (int i = n; i < n + m; ++i) {
    int x;
    cin >> x;
    hp[i] = atk[i] = x;
    b.insert({0, i});
  }
  function<pair<double, double>(decltype(a), decltype(b))> dfs =
      [&](set<pair<int, int>> a,
          set<pair<int, int>> b) -> pair<double, double> {
    auto na = a, nb = b;
    double wa = 1, wb = 1;
    auto ca = *na.begin();
    auto cb = *nb.begin();
    auto ia = ca.second;
    auto ib = cb.second;
  };
  dfs(a, b);
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
