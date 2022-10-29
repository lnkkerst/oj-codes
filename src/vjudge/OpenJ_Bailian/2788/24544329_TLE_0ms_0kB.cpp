#include <cmath>
#include <iostream>
#define int long long
using namespace std;

int n, m;

signed main() {
  while (cin >> m >> n) {
    if (!m && !n)
      return 0;
    int l2n = (int)log2l(n), l2m = (int)log2l(m);
    int ans = (1 << (l2n - l2m + 1)) - 1;
    for (int i = n + 1; i <= ((1 << (l2n + 1)) - 1); ++i) {
      int t = i;
      while (t != 1 && t != m)
        t >>= 1;
      if (t == m)
        --ans;
    }
    cout << ans << endl;
  }
  return 0;
}