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

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  int g = x * y / gcd(x, y);
  int ans = 0;
  int ng = n / g;
  int nx = n / x;
  nx -= ng;
  ans += n * nx - (nx * (nx - 1)) / 2;
  int ny = n / y;
  ny -= ng;
  ans -= 1 * ny + (ny * (ny - 1)) / 2;
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
