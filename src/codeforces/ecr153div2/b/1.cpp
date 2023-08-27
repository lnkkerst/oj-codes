#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int m, k, a1, ak;
  cin >> m >> k >> a1 >> ak;
  int uk = m / k;
  int u1 = m - (uk * k);
  if (a1 > u1) {
    ak += (a1 - u1) / k;
  }
  int ans = max(uk - ak, 0ll) + max(u1 - a1, 0ll);
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
