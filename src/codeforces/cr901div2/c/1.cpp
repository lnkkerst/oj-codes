#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  if (n % m == 0) {
    cout << 0 << endl;
    return;
  }
  int cnt = 0;
  int bm = m;
  while (!(m & 1)) {
    m >>= 1;
    ++cnt;
  }
  if (n % m != 0) {
    cout << -1 << endl;
    return;
  }
  m = bm;
  unordered_map<int, int> b;
  int ans = 0;
  while (true) {
    while (n < m) {
      ans += n;
      n <<= 1;
    }
    n = n % m;
    if (b[n]) {
      cout << -1 << endl;
      return;
    }
    int bm = m;
    int bn = n;
    if (n == 0) {
      cout << ans << endl;
      return;
    }
    b[n] = true;
  }
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
