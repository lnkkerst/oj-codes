#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
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
  vector<string> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (a[i][j] == 'c' && a[i][j + 1] == 'c' && a[i + 1][j] == 'p' &&
          a[i + 1][j + 1] == 'c') {
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
}
