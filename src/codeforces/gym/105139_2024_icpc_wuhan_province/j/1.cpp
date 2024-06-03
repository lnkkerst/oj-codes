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

inline constexpr int MOD = 998244353;

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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int su = 0;
  for (auto &i : a) {
    cin >> i;
    su += i;
    su %= MOD;
  }
  cout << su * inv(n) % MOD << endl;
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
