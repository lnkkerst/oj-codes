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
  int n, a, b;
  cin >> n >> a >> b;
  map<int, map<int, int>> bk;
  for (int i = 1; i <= n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j < x2; ++j) {
      for (int k = y1; k < y2; ++k) {
        bk[j][k] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      ans += bk[i][j];
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
