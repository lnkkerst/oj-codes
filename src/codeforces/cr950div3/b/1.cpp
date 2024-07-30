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
  int n, f, k;
  cin >> n >> f >> k;
  vector<int> a(n + 1);
  int gt = 0, ge = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] > a[f]) {
      ++gt;
    }
    if (a[i] >= a[f]) {
      ++ge;
    }
  }
  if (gt >= k) {
    cout << "NO" << endl;
    return;
  }
  if (ge <= k) {
    cout << "YES" << endl;
    return;
  }
  cout << "MAYBE" << endl;
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
