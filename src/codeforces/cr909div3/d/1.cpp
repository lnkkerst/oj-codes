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
  vector<int> a(n + 1);
  map<int, int> b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++b[a[i]];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = a[i] - 1, k = 1; k <= 30 && j >= 1; --j, ++k) {
      if (a[i] % j == 0 && a[i] / j == (1 << (a[i] - j))) {
        // cout << i << ' ' << a[i] << ' ' << j << endl;
        ans += max(0ll, b[j]);
      }
    }
  }
  for (auto [k, i] : b) {
    if (i) {
      ans += (i * i - i) / 2;
    }
  }
  cout << ans << endl;
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
