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
  int n, k, x;
  cin >> n >> k >> x;
  if (k > n || k > x + 1) {
    cout << -1 << endl;
    return;
  }
  int ans = 0;
  ans += (k * (k - 1)) / 2;
  if (k != x) {
    ans += (n - k) * x;
  } else {
    ans += (n - k) * (x - 1);
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
