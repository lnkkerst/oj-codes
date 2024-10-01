#include <iostream>
using namespace std;

#define int long long

void solve() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int cnt0 = 0;
  for (int i = 0; i < 3; ++i) {
    cnt0 += a[i] == 0;
  }
  if (cnt0 == 3) {
    cout << "YES\n1 1 1" << endl;
    return;
  }
  for (int i = 0; i < 3; ++i) {
    int x = a[(i + 0) % 3], y = a[(i + 1) % 3], z = a[(i + 2) % 3];
    int ta = x, tc = ta * 2 + z;
    if (tc == 0) {
      continue;
    }
    int tk = max(1ll, (ta - y + tc - 1) / tc);
    int tb = tk * tc + y;
    if (ta >= 1 && ta <= (int)1e18 && tb >= 1 && tb <= (int)1e18 && tc >= 1
        && tc <= (int)1e18 && ta % tb == x && tb % tc == y && tc % ta == z) {
      int ans[3];
      ans[i] = ta;
      ans[(i + 1) % 3] = tb;
      ans[(i + 2) % 3] = tc;
      cout << "YES" << endl;
      for (int i = 0; i < 3; ++i) {
        cout << ans[i] << ' ';
      }
      cout << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
