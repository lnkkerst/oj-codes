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

#define int __int128_t
using ll = long long;

void solve() {
  ll n;
  cin >> n;
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    ll x;
    cin >> x;
    tot += x;
  }
  auto find = [&](int x) {
    for (int i = 0; (1ll << i) <= x; ++i) {
      if ((((int)1ll << (i + 1)) - 1) * n >= x) {
        return i;
      }
    }
    throw 114514;
  };
  int ans = 0;
  while (tot) {
    int x = find(tot);
    ans += ((int)1ll << x);
    // tot %= ((int)1ll << x);
    tot = max(tot % (1ll << x), tot - (1ll << x) * n);
  }
  cout << (ll)ans << endl;
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
