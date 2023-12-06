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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &[l, _] : a) {
    cin >> l;
  }
  for (auto &[_, r] : a) {
    cin >> r;
  }
  sort(a.begin(), a.end());
  int tot = 0;
  for (auto [l, r] : a) {
    tot += r - l + 1;
  }
  if (tot < k) {
    cout << -1 << endl;
    return;
  }
  int ans = 1e18;
  int c1 = 0;
  int cur = 0;
  int cnt = 0;
  for (auto [l, r] : a) {
    int sz = r - l + 1;
    if (sz > 1) {
      cur += sz;
      ++cnt;
    } else {
      ++c1;
    }
    if (cur < k) {
      if (cur + c1 >= k) {
        ans = min(ans, r + 2 * (cnt + k - cur));
      }
    } else {
      ans = min(ans, r - (cur - k) + 2 * cnt);
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
