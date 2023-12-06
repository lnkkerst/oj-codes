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

#define endl "\n"

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int mi = n + m - 2;
  if (k < mi) {
    cout << "NO" << endl;
    return;
  }
  k -= (k - mi) / 4 * 4;
  if ((k - mi) & 1) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  auto fn = [&](int n, int m) {
    int cur = 0;
    for (int j = 1; j <= m - 1; ++j) {
      cout << (cur ? "R" : "B") << ' ';
      cur = !cur;
    }
    cout << endl;
    cur = 0;
    for (int j = 1; j <= m - 1; ++j) {
      cout << (cur ? "R" : "B") << ' ';
      cur = !cur;
    }
    cout << endl;
    int br = cur;
    cur = 0;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j <= m - 1; ++j) {
        cout << (cur ? "R" : "B") << ' ';
      }
      cout << endl;
      cur = !cur;
    }
    cur = 1;
    for (int i = 1; i <= n - 1; ++i) {
      for (int j = 1; j <= m - 1; ++j) {
        cout << (cur ? "R" : "B") << ' ';
      }
      cout << (br ? "R" : "B") << ' ';
      br = !br;
      cout << endl;
      cur = !cur;
    }
  };
  if (k - mi == 0) {
    fn(n, m);
    return;
  }
  map<int, map<int, int>> a, b;
  a[1][1] = 1;
  a[2][1] = 1;
  b[2][1] = 1;
  b[2][2] = 1;
  b[2][3] = 1;
  int cur = 0;
  for (int i = 3; i <= m - 1; ++i) {
    a[3][i] = cur;
    cur = !cur;
  }
  for (int i = 3; i <= n - 1; ++i) {
    b[i][m] = cur;
    cur = !cur;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m - 1; ++j) {
      cout << (a[i][j] ? "R" : "B") << ' ';
    }
    cout << endl;
  }
  for (int i = 1; i <= n - 1; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << (b[i][j] ? "R" : "B") << ' ';
    }
    cout << endl;
  }
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
