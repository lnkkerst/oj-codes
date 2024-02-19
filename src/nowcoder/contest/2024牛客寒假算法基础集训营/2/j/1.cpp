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
  int n;
  cin >> n;
  vector<int> a(n);
  int tot = 0;
  for (auto &i : a) {
    cin >> i;
    tot += i;
  }
  int ans = 0;
  sort(a.begin(), a.end());
  int curl = 0;
  int curh = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[0] * 4 * curh;
    ans += curl * 2;
    if (i == 0 || a[i] <= 2 * a[0]) {
      ans += a[i] * 2 * (n - i - 1);
    } else {
      ans += a[0] * 4 * (n - i - 1);
    }
    if (a[i] <= 2 * a[0]) {
      curl += a[i];
    } else {
      ++curh;
    }
  }
  cout << ans << endl;
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
