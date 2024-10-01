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

constexpr int MOD = 998244353;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= p;
    }
    x *= x;
    x %= p;
    k >>= 1;
  }
  return res;
}

int inv(int x) {
  return qmi(x, MOD - 2, MOD);
}

int frac(int x, int y) {
  return x * inv(y) % MOD;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n * 2; ++i) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans -= a[i];
  }
  for (int i = n + 1; i <= n * 2; ++i) {
    ans += a[i];
  }
  ans %= MOD;
  for (int i = n + 1; i <= n * 2; ++i) {
    ans *= i;
    ans %= MOD;
  }
  for (int i = 1; i <= n; ++i) {
    ans = frac(ans, i);
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
