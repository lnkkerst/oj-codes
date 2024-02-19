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
  vector<ll> a(n);
  map<int, map<int, int>> b;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    a[i] = x;
    int len = to_string(a[i]).length();
    ++b[len][a[i] % 36];
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int len = to_string(a[i]).length();
    --b[len][a[i] % 36];
    for (int j = 1; j <= 18; ++j) {
      x *= 10;
      int lx = x % 36;
      ans += b[j][(36 - lx) % 36];
    }
    ++b[len][a[i] % 36];
  }
  cout << ans << endl;
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
