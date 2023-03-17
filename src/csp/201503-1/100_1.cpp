#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int j = m - 1; j >= 0; --j) {
    for (int i = 0; i < n; ++i) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
