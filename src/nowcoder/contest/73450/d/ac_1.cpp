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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<vector<int>> b(n, vector<int>(m));
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int mxx = -1, mxy = -1, msx = 1e9, msy = 1e9;
      int cnt = 0;
      function<void(int, int)> dfs = [&](int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
          return;
        };
        if (b[x][y]) {
          return;
        }
        if (a[x][y] == '*') {
          return;
        }
        b[x][y] = true;
        mxx = max(mxx, x);
        mxy = max(mxy, y);
        msx = min(msx, x);
        msy = min(msy, y);
        ++cnt;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; ++i) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          dfs(nx, ny);
        }
      };
      if (a[i][j] == '.' && !b[i][j]) {
        dfs(i, j);
        int h = mxx - msx + 1;
        int w = mxy - msy + 1;
        if (h * w == cnt) {
          ++ans;
        }
      }
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
