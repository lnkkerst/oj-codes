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

using Tree = tree<int, null_type, less<int>, rb_tree_tag,
                  tree_order_statistics_node_update>;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[l, r] : a) {
    cin >> l >> r;
  }
  map<int, int> b;
  for (int i = 0; i < n; ++i) {
    b[a[i].first] = (i + 1);
    b[a[i].second] = -(i + 1);
  }
  int top = 0;
  vector<int> id(n + 1);
  int cur = 0;
  vector<int> last(n + 1);
  Tree tr;
  int ans = 0;
  vector<int> lp(n + 1);
  for (auto [k, e] : b) {
    if (e > 0) {
      id[e] = top++;
      last[id[e]] = cur;
      tr.insert(id[e]);
      lp[id[e]] = tr.order_of_key(id[e]);
    } else {
      ans += cur - last[id[-e]] - (lp[id[-e]] - tr.order_of_key(id[-e]));
      ++cur;
      tr.erase(id[-e]);
    }
  }
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
