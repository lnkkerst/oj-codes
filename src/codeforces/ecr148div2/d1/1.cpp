#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> aa(n);
  for (auto &i : aa) {
    cin >> i;
  }
  sort(aa.begin(), aa.end());
  while (q--) {
    int k;
    cin >> k;
    if (k <= n) {
      int ans = 2e18;
      for (int i = 0; i < n; ++i, k = max(0ll, k - 1)) {
        ans = min(ans, aa[i] + k);
      }
      cout << ans << ' ';
      continue;
    }
    int re = k - n;
    if (re & 1) {
      ++re;
    }
    auto &a = aa;
    for (int i = 0, j = k, cj = 0; i < n && j > 0 && cj < k - re;
         ++i, --j, ++cj) {
      a[i] += j;
    }
    int l = -1e18, r = 1e18;
    re /= 2;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      int cnt = 0;
      bool fl = false;
      for (int j = 0; j < n; ++j) {
        int i = a[j] + max(0ll, a[j] + (k - j));
        if (i < mid) {
          fl = true;
          break;
        }
        cnt += i - mid;
      }
      if (fl || cnt < re) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    cout << l << ' ';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
