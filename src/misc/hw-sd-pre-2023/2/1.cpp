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
  int n, m;
  cin >> n >> m;
  int cx, cy;
  cin >> cx >> cy;
  vector<int> ax(cx), ay(cy);
  for (auto &i : ax) {
    cin >> i;
  }
  for (auto &i : ay) {
    cin >> i;
  }
  sort(ax.begin(), ax.end());
  sort(ay.begin(), ay.end());
  auto query = [&](const vector<int> &a, int l, int r) -> int {
    auto it = lower_bound(a.begin(), a.end(), l);
    if (it == a.end()) {
      return 0;
    }
    int ld = it - a.begin();
    it = upper_bound(a.begin(), a.end(), r);
    if (it == a.begin()) {
      return 0;
    }
    --it;
    int rd = it - a.begin();
    return rd - ld + 1;
  };
  int ans = 0;
  ans += (query(ax, -n + 1, n - 1) + 1) * (query(ay, m + 1, n - 1) + 1);
  ans += (query(ax, -n + 1, n - 1) + 1) * (query(ay, -n + 1, -m - 1) + 1);
  int xd = query(ax, -n + 1, -m - 1) + query(ax, m + 1, n - 1);
  int yd = query(ay, -m, m);
  ans += (yd - 1) * (xd + 2);
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
