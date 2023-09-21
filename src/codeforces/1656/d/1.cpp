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
  int x = n;
  while (!(x & 1)) {
    x >>= 1;
  }
  if (x == 1) {
    cout << -1 << endl;
    return;
  }
  if (x <= 2e9 && (x * (x + 1)) / 2 <= n) {
    cout << x << endl;
    return;
  }
  cout << n / x * 2 << endl;
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
