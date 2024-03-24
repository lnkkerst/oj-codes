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
  int bm = m;
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
  ans = max(ans, cur);
  if (m) {
    ans = max(ans, cur + m * mx);
  }

  m = bm;

  vector<int> px(n);
  px[0] = a[0].first;
  for (int i = 1; i < n; ++i) {
    px[i] = px[i - 1] + a[i].first;
  }

  for (int i = 0; i < n; ++i) {
    auto it = upper_bound(a.begin(), a.end(), make_pair(a[i].second, 2e9),
                          greater<pair<int, int>>());
    // cout << it - a.begin() << endl;
    if (it == a.end()) {
      continue;
    }
    int in = it - a.begin();
    if (in >= m) {
      continue;
    }
    int t = 0;
    if (in) {
      t += px[in - 1];
    }
    int rm = m - in;
    if (in - 1 >= i) {
      t += a[i].second * rm;
    } else {
      t += a[i].first;
      rm--;
      if (rm) {
        t += a[i].second * rm;
      }
    }
    ans = max(ans, t);
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
