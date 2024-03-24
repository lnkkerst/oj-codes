
#pragma GCC optimize(2)
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> m >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  sort(a.begin(), a.end(), greater<>());
  int ma = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].second > a[ma].second) {
      ma = i;
    }
  }
  int mx = a[ma].second;
  bool fl = false;
  int ans = 0;
  int last = -1;
  int cur = 0;
  int cma = 0;
  if (m != 0) {
    ans = max(ans, cur + a[ma].first + (m - 1) * mx);
  }
  for (int i = 0; i < n && m; ++i) {
    cout << ans << endl;
    cma = max(cma, a[i].second);
    cur += a[i].first;
    --m;
    if (i == ma) {
      fl = true;
    }
    ans = max(ans, cur + m * cma);
    if (fl) {
      ans = max(ans, cur + m * mx);
    } else {
      if (m != 0) {
        ans = max(ans, cur + a[ma].first + (m - 1) * mx);
      }
    }
  }
  if (m) {
    ans = max(ans, cur + m * mx);
  }
  cout << ans << endl;
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
