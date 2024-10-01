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
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > x) {
      bool fl = false;
      for (int j = i; j < n; ++j) {
        if (a[j] > a[j + 1]) {
          fl = true;
          break;
        }
      }
      if (fl) {
        swap(a[i], x);
        ++ans;
      }
    }
  }
  if (is_sorted(a.begin() + 1, a.end())) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
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
