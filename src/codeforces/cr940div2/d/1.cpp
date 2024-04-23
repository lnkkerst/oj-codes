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
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> p1(32, vector<int>(n + 2));
  auto pl = p1;
  auto pr = p1;
  for (int i = 0; i <= 30; ++i) {
    pl[i][0] = pr[i][0] = 1;
    pl[i][n + 1] = pr[i][n + 1] = 1;
    for (int j = 1; j <= n; ++j) {
      int x = a[j];
      int bx = (x >> i) & 1;
      p1[i][j] = p1[i][j - 1] + bx;
      pl[i][j] = pl[i][j - 1] + (p1[i][j] % 2 == 0);
    }
    int c1 = 0;
    for (int j = n; j >= 1; --j) {
      int x = a[j];
      int bx = (x >> i) & 1;
      c1 += bx;
      pr[i][j] = pr[i][j + 1] + (c1 % 2 == 0);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int f1 = 0;
    for (int j = 30; j >= 0; --j) {
      if ((a[i] >> j) & 1) {
        f1 = j;
        break;
      }
    }
    int t1, t2;
    if (p1[f1][i] & 1) {
      t1 = pl[f1][i - 1];
      if (p1[f1][n] & 1) {
        t2 = pr[f1][i + 1];
      } else {
        t2 = n - i + 1 - pr[f1][i + 1];
      }
    } else {
      t1 = i - pl[f1][i - 1];
      if (p1[f1][n] & 1) {
        t2 = n - i + 1 - pr[f1][i + 1];
      } else {
        t2 = pr[f1][i + 1];
      }
    }
    ans += t1 * (n - i + 1 - t2) + t2 * (i - t1);
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
