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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto p = a;
  for (int i = 1; i < n; ++i) {
    p[i] ^= p[i - 1];
  }
  int ans = 0;
  for (int k = 0; k <= 20; ++k) {
    int c0 = 1, c1 = 0;
    for (auto x : p) {
      if ((x >> k) & 1) {
        ++c1;
      } else {
        ++c0;
      }
    }
    ans += (1ll << k) * (c0 * c1);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
