#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  auto b = a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    int mi = 1e9;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] < mi) {
        mi = a[i][j];
      }
    }
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == mi) {
        ++b[i][j];
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    int mi = 1e9;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] < mi) {
        mi = a[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == mi) {
        ++b[i][j];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] == 2) {
        ++ans;
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
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
