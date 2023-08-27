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
  map<int, int> b[4];
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    ++b[0][x];
    ++b[1][y];
    ++b[2][y - x];
    ++b[3][y + x];
  }
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    for (auto x : b[i]) {
      int cnt = x.second;
      ans += (cnt * cnt - cnt);
    }
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
