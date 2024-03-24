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
  vector<pair<int, int>> a(n);
  int t1 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    t1 += a[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].second;
  }
  if (t1 < m) {
    cout << -1 << endl;
  }
  sort(a.begin(), a.end(),
       [&](const pair<int, int> a, const pair<int, int> b) -> bool {
         int ta = a.first * 2 / a.second;
         int tb = b.first * 2 / b.second;
         return ta > tb;
       });
  // for (auto [v, w] : a) {
  //   cout << v << ' ' << w << endl;
  // }
  int cur = 0;
  int pos = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (cur + a[i].first > m) {
      if (a[i].second == 1) {
        cout << ans + 1 << endl;
        return;
      }
      bool fl = false;
      for (int j = i + 1; j < n; ++j) {
        if (a[j].second == 1 && a[j].first >= m - cur) {
          fl = true;
          break;
        }
      }
      if (fl) {
        cout << ans + 1 << endl;
        return;
      }
      fl = false;
      for (int j = 0; j <= i - 1; ++j) {
        if (a[j].second == 1 && cur - a[j].first + a[i].first >= m) {
          fl = true;
          break;
        }
      }
      if (fl) {
        cout << ans + 1 << endl;
        return;
      }
      cout << ans + 2 << endl;
      return;
    }
    cur += a[i].first;
    ans += a[i].second;
    if (cur == m) {
      cout << ans << endl;
      return;
    }
  }
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
