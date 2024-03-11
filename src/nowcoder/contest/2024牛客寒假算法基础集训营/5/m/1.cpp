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
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(2));
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][0];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][1];
  }
  if (n == 1) {
    cout << -1 << endl;
    return;
  }
  for (int i = 2; i <= n - 1; ++i) {
    if (a[i][0] == a[i][1]) {
      cout << 1 << endl;
      return;
    }
  }
  for (int i = 2; i <= n; ++i) {
    if ((a[i][0] == a[i - 1][1]) || (a[i][1] == a[i - 1][0])) {
      cout << 1 << endl;
      return;
    }
  }
  if (n == 2) {
    cout << -1 << endl;
  } else {
    cout << 2 << endl;
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
