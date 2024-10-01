#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
int fac[1096 + 10];
int n, k;

void initFac() {
  fac[0] = 1;
  for (int i = 1; i <= 1096; ++i) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
}

int fastPower(int x, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = res * x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    b >>= 1;
  }
  return res;
}

int calc(int n, int m) {
  return (fac[n] * fastPower(fac[m], MOD - 2) % MOD
          * fastPower(fac[n - m], MOD - 2))
         % MOD;
}

signed main() {
  initFac();
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a.emplace_back(x);
    }
    sort(a.begin(), a.end(), greater<>());
    --k;
    int cnt = 0;
    int need = 0;
    for (auto i : a) {
      if (i == a[k]) {
        ++cnt;
      }
    }
    for (int i = k; i >= 0; --i) {
      if (a[i] == a[k]) {
        ++need;
      }
    }
    cout << calc(cnt, need) << endl;
  }
  return 0;
}
