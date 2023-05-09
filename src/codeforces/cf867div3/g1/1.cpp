#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[2000000];
  int b[2000000] = {};
  int ansb[2000000] = {};
  int ans = 0;
  int ma = -1e9;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++b[a[i]];
    ma = max(ma, a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (ansb[a[i]]) {
      continue;
    }
    ansb[a[i]] = true;
    for (int j = 1; a[i] * j * j <= ma; ++j) {
      int tmp = b[a[i]];
      --b[a[i]];
      if (b[a[i] * j]) {
        tmp *= b[a[i] * j];
        --b[a[i] * j];
        if (b[a[i] * j * j]) {
          ans += tmp * b[a[i] * j * j];
          ansb[a[i]] = tmp * b[a[i] * j * j];
        }
        ++b[a[i] * j];
      }
      ++b[a[i]];
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
