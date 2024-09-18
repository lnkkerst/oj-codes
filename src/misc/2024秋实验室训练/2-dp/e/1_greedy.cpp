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

void solve() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);
  set<int> s;
  for (auto &[l, r] : a) {
    cin >> l >> r;
  }
  int cid = 0;
  map<int, int> id;
  map<int, int> mp;
  for (auto x : s) {
    id[x] = cid;
    mp[cid] = x;
    ++cid;
  }
  // for (auto &[l, r] : a) {
  //   l = id[l];
  //   r = id[r];
  // }
  int ans = 0;
  int cl = x, cr = x;
  for (auto [l, r] : a) {
    if (cr < l) {
      ans += l - cr;
      cl = cr;
      cr = l;
    } else if (cl > r) {
      ans += cl - r;
      cr = cl;
      cl = r;
    } else {
      cl = max(cl, l);
      cr = min(cr, r);
    }
  }
  cout << ans << endl;
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
