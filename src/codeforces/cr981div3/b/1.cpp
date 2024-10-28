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
  int ans = 0;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n - 1; ++i) {
    int x = n - i + 1, y = 1;
    int mi = 1e9;
    while (x <= n && y <= n) {
      mi = min(mi, a[x][y]);
      ++x, ++y;
    }
    ans += max(0ll, -mi);
  }
  for (int i = 1; i <= n; ++i) {
    int x = 1, y = i;
    int mi = 1e9;
    while (x <= n && y <= n) {
      mi = min(mi, a[x][y]);
      ++x, ++y;
    }
    ans += max(0ll, -mi);
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
