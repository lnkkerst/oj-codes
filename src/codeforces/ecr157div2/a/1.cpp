#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  int x, y, k;
  cin >> x >> y >> k;
  if (y <= x) {
    cout << x << endl;
    return;
  }
  if (y - x <= k) {
    cout << y << endl;
    return;
  }
  cout << y + (y - (x + k)) << endl;
  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
