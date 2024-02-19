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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (auto &[v, w] : a) {
    cin >> v >> w;
  }
  auto calc = [&](int x) {
    // cout << x << endl;
    int res = 0;
    for (auto [v, w] : a) {
      if ((w | x) == x) {
        res += v;
      }
    }
    return res;
  };
  int ans = calc(m);
  for (int i = 0; i <= 30; ++i) {
    if ((m >> i) & 1) {
      int x = m;
      x ^= (1ll << i);
      for (int j = 0; j < i; ++j) {
        (x |= (1ll << j));
      }
      ans = max(ans, calc(x));
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
