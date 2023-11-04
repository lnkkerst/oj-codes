#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  int su = 0;
  tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag,
       tree_order_statistics_node_update>
      tr;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    su += a[i] + b[i];
    tr.insert({b[i] - a[i], i + 1});
  }
  auto calc = [&]() {
    int diff = 0;
    int curi = -1;
    int rb = 0, ra = 0;
    for (auto [v, i] : tr) {
      ++curi;
      if (curi == 0) {
        diff += v;
        ++ra;
        continue;
      }
      if (curi % 4 == 1 || curi % 4 == 2) {
        if (v < 0 && ra > 0) {
          --ra;
        } else {
          diff -= v;
          ++rb;
        }
      } else {
        if (v < 0 && rb > 0) {
          --rb;
        } else {
          diff += v;
          ++ra;
        }
      }
      cout << curi << ' ' << ra << ' ' << rb << ' ' << diff << ' ' << v << endl;
    }
    return (su - diff) / 2;
  };
  cout << calc() << endl;
  for (int i = n + 1; i <= n + m; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    --t;
    int od = b[t] - a[t];
    auto it = tr.lower_bound({od, n + m + 1});
    tr.erase(it);
    tr.insert({y - x, i});
    su -= b[t];
    su -= a[t];
    su += y;
    su += x;
    b[t] = y;
    a[t] = x;
    cout << calc() << endl;
  }
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
