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

int sgn(int x) {
  if (x > 0) {
    return 1;
  } else if (x == 0) {
    return 0;
  } else {
    return -1;
  }
}

void solve() {
  int t, a, k;
  cin >> t >> a >> k;
  if (-k <= a && a <= k) {
    cout << abs(a) + abs(a - t) << endl;
    return;
  }
  if ((0 <= a && a <= t) || (t <= a && a <= 0)) {
    cout << abs(a) + abs(a - t) << endl;
    return;
  }
  cout << abs(t) + abs(a - t) + abs(a - t) << endl;
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
