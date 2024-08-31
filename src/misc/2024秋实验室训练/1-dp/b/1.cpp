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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> c;
  int last = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] > a[i - 1]) {
    } else {
      c.emplace_back(last, i - 1);
      last = i;
    }
  }
  if (last) {
    c.emplace_back(last, n);
  }
  int ans = 0;
  for (auto [l, r] : c) {
    ans = max(ans, r - l + 1);
  }
  for (int i = 1; i < c.size(); ++i) {
    int lenl = c[i - 1].second - c[i - 1].first + 1;
    int lenr = c[i].second - c[i].first + 1;
    if (lenl > 1) {
      if (a[c[i - 1].second - 1] < a[c[i].first]) {
        ans = max(ans, lenl + lenr - 1);
      }
    }
    if (lenr > 1) {
      if (a[c[i].first + 1] > a[c[i - 1].second]) {
        ans = max(ans, lenl + lenr - 1);
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
