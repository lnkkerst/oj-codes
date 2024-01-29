#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int x, y, l, r;
  cin >> x >> y >> l >> r;
  int g = __gcd(x, y);
  x /= g;
  y /= g;
  int ans = 0;
  int mi = min(x, y);
  int ma = max(x, y);
  ans = (r / ma) - ((l - 1) / mi);
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
