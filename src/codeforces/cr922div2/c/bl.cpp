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
  int a, b, r;
  cin >> a >> b >> r;
  int ans = 2e18;
  int ap = 0;
  for (int i = 0; i <= r; ++i) {
    cout << abs((a ^ i) - (b ^ i)) << ' ';
    if (ans > abs((a ^ i) - (b ^ i))) {
      ans = min(ans, abs((a ^ i) - (b ^ i)));
      ap = i;
    }
  }
  cout << endl;
  cout << ans << ' ' << ap << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
