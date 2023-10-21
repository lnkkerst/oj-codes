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

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> b;
  for (auto &i : a) {
    cin >> i;
    ++b[i];
  }
  sort(a.begin(), a.end());
  auto calc = [&](vector<int> a) {
    sort(a.begin(), a.end());
    if (a.front() != 0) {
      return 0ll;
    }
    for (int i = 0; i < a.size() - 1; ++i) {
      if (a[i] != a[i + 1] && a[i] != a[i + 1] - 1) {
        return a[i] + 1ll;
      }
    }
    return a.back() + 1ll;
  };
  if (!b[0]) {
    cout << 0 << endl;
    return;
  }
  int cur = calc(a);
  int ans = (b[0] - 1) * cur;
  int base = 0;
  while (true) {
    int tc = cur;
    int tt = ans;
    for (auto [x, c] : b) {
      if (x == 0 || c == 0) {
        continue;
      }
      if (x > cur) {
        break;
      }
      int t = (c - 1) * cur + b[0] * x;
      if (t + base < tt) {
        tc = x;
        tt = t + base;
      }
    }
    if (tc == cur) {
      break;
    }
    ans = min(ans, tt);
    base += (b[tc] - 1) * cur + tc;
    cur = tc;
  }
  cout << ans << endl;
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
