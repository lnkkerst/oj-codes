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

inline constexpr int MOD = 1e9 + 7;
inline constexpr int MAXN = 3e5 + 10;

vector<int> f(MAXN + 1);
vector<int> fm(MAXN + 1);

void init() {
  f[0] = 1;
  for (int i = 1; i <= MAXN; ++i) {
    f[i] = f[i - 1] * i % MOD;
  }
  fm[0] = 1;
  for (int i = 1; i <= MAXN; ++i) {
    fm[i] = fm[i - 1] * (i * (2 * i - 1) % MOD) * 2 % MOD;
  }
  // for (int i = 1; i <= 10; ++i) {
  //   cout << fm[i] << endl;
  // }
}

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    k >>= 1;
  }
  return res;
}

int inv(int x) {
  return qmi(x, MOD - 2, MOD);
}

int C(int n, int m) {
  return f[n] * inv(f[m] * f[n - m] % MOD) % MOD;
}

void solve() {
  int n, k;
  cin >> n >> k;
  int c0 = 0, c1 = 0;
  for (int i = 1; i <= k; ++i) {
    int r, c;
    cin >> r >> c;
    if (r != c) {
      ++c0;
    } else {
      ++c1;
    }
  }
  int ans = 0;
  int rr = c0 * 2 + c1;
  int rest = n - rr;
  for (int i = 0; i <= rest; i += 2) {
    ans += C(rest, i + (rest & 1)) * fm[(rest - i) / 2] % MOD
           * inv(f[(rest - i) / 2]) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
