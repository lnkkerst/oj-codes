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
  vector<vector<int>> a(n, vector<int>(m));
  auto b = a;
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  if (n == 1 && m == 1) {
    cout << -1 << endl;
    return;
  }
  if (m != 1) {
    for (int i = 0; i < n; ++i) {
      b[i][0] = a[i][m - 1];
      for (int j = 1; j < m; ++j) {
        b[i][j] = a[i][j - 1];
      }
    }
  }
  if (n != 1) {
    for (int j = 0; j < m; ++j) {
      b[0][j] = a[n - 1][j];
      for (int i = 1; i < n; ++i) {
        b[i][j] = a[i - 1][j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << b[i][j] << " ";
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
