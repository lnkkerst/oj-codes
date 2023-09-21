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
  int n;
  cin >> n;
  int c3 = n / 3;
  int ans = 0;
  ans += (n - c3 * 3) * c3 + (c3 * (c3 - 1)) / 2 * 3;
  ans += (c3 + (c3 * (c3 - 1)) / 2) * 2;
  cout << ans << endl;
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
