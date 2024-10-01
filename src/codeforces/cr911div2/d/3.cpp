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

#define int long long

using Tree = tree<int, null_type, less_equal<>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  Tree s;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    auto ts = s;
    ts.erase(ts.lower_bound(a[i] - 1));
    for (int j = i + 1; j <= n; ++j) {
      ts.erase(ts.lower_bound(a[j] - 1));
      auto it = ts.order_of_key(max(a[i], a[j]));
      auto cnt = ts.size() - it;
      ans += gcd(a[i], a[j]) * cnt;
      ts.insert(a[j]);
    }
  }
  cout << ans << endl;
}

signed main() {
  // Tree tr;
  // tr.insert(1);
  // tr.insert(1);
  // tr.insert(2);
  // tr.insert(3);
  // cout << tr.order_of_key(3);
  // cout << endl;
  // tr.erase(tr.lower_bound(2 - 1));
  // for (auto i : tr) {
  //   cout << i << ' ';
  // }
  // cout << endl;
  // return 0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
