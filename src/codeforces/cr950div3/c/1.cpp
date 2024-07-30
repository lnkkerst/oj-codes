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
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  map<int, int> bb;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    bb[b[i]] = 1;
  }
  int m;
  cin >> m;
  vector<int> d(m + 1);
  map<int, int> bk;
  for (int i = 1; i <= m; ++i) {
    cin >> d[i];
    ++bk[d[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) {
      --bk[b[i]];
    }
  }
  if (!bb[d[m]]) {
    cout << "NO" << endl;
    return;
  }
  for (auto [k, v] : bk) {
    if (v < 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
