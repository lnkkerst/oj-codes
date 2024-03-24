#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long

inline constexpr int MOD = 1e9 + 7;

vector<int> fr(3003);

void init() {
  fr[0] = 1;
  for (int i = 1; i <= 3000; ++i) {
    fr[i] = fr[i - 1] * i;
    fr[i] %= MOD;
  }
}

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
  return qmi(x, MOD - 2, MOD) % MOD;
}

int C(int n, int m) {
  int res = fr[n];
  res = res * inv(fr[n - m]) % MOD;
  res = res * inv(fr[m]) % MOD;
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> b;
  for (auto &i : a) {
    cin >> i;
    ++b[i];
  }
  sort(a.begin(), a.end(), greater<>());
  int mx = 0;
  map<int, int> b2;
  for (int i = 0; i < k; ++i) {
    mx += a[i];
    ++b2[a[i]];
  }
  int ans = 1;
  for (auto [k, v] : b2) {
    ans = ans * C(b[k], v) % MOD;
  }
  cout << (ans % MOD + MOD) % MOD << endl;
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

  return 0;
}
