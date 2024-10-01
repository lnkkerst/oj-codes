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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 2e18;
  int cur = 0;
  for (int i = 0; i < n - 1; ++i) {
    cur += abs(a[i] - a[i + 1]);
  }
  auto run = [&]() {
    int mi = a[0] - 1;
    ans = min(ans, cur + abs(a[0] - m) + (m - 1));
    for (int i = 0; i < n - 1; ++i) {
      ans = min(ans, cur + mi - abs(a[i] - a[i + 1]) + abs(a[i] - m)
                       + abs(a[i + 1] - m));
      ans = min(ans, cur - abs(a[i] - a[i + 1]) + abs(a[i] - m)
                       + abs(a[i + 1] - 1) + (m - 1));
      mi = min(mi,
               0ll - abs(a[i] - a[i + 1]) + abs(a[i] - 1) + abs(a[i + 1] - 1));
    }
    ans = min(ans, cur + mi + abs(a.back() - m));
  };
  run();
  reverse(a.begin(), a.end());
  run();
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
