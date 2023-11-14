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
  int n, m;
  cin >> n >> m;
  vector<int> dx(n), dy(n);
  for (int i = 0; i < n; ++i) {
    cin >> dx[i] >> dy[i];
  }
  int ax = accumulate(dx.begin(), dx.end(), 0);
  int ay = accumulate(dy.begin(), dy.end(), 0);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    cout << x + ax << ' ' << y + ay << endl;
  }
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
