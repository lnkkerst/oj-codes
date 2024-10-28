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
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> a(n + 1);
  int rg = 0;
  for (int i = 1; i <= n; ++i) {
    auto &[x, y] = a[i];
    cin >> x >> y;
    rg = max(rg, x);
  }
  vector<int> mx(rg + 1, 0), mn(rg + 1, 1e9);
  for (int i = 1; i <= n; ++i) {
    auto [x, y] = a[i];
    mx[x] = max(mx[x], y);
    mn[x] = min(mn[x], y);
  }
  int l = 0, r = rg + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    deque<int> qn, qx;
    bool fl = false;
    for (int i = 1; i <= rg; ++i) {
      while (!qn.empty() && mn[qn.back()] > mn[i]) {
        qn.pop_back();
      }
      qn.emplace_back(i);
      while (i - qn.front() >= mid) {
        qn.pop_front();
      }
      while (!qx.empty() && mx[qx.back()] < mx[i]) {
        qx.pop_back();
      }
      qx.emplace_back(i);
      while (i - qx.front() >= mid) {
        qx.pop_front();
      }
      if (mx[qx.front()] - mn[qn.front()] >= d) {
        fl = true;
        break;
      }
    }
    if (fl) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (r >= rg + 1) {
    cout << -1 << endl;
    return;
  }
  cout << r - 1 << endl;
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
