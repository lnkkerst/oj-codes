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

inline constexpr int MOD = 998244353;

void solve() {
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  string s;
  cin >> s;
  map<int, map<int, int>> mp;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    mp[x][y] = 1;
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int cx = sx, cy = sy;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        int dx = 0, dy = 0;
        if (s[j] == 'L') {
          dx = -1;
        }
        if (s[j] == 'R') {
          dx = 1;
        }
        if (s[j] == 'U') {
          dy = 1;
        }
        if (s[j] == 'D') {
          dy = -1;
        }
        int nx = cx + dx;
        int ny = cy + dy;
        if (!mp[nx][ny]) {
          cx = nx;
          cy = ny;
        }
      }
    }
    if (cx == sx && cy == sy) {
      ++ans;
    }
  }
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
