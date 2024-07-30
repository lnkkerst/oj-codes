/*********************************************************************
    $PROGRAM$:
    $COPYRIGHT$:
    $AUTHOR$:
    $DATETIME$: 2024/7/25 15:16:01
    $DESCRIPTION$:
*********************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#ifdef Debug
#define D() cerr << __LINE__ << endl;
#else
#define D()
#endif
#define ll long long
#define ull unsigned long long
#define mod 998244353
using namespace std;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
const ll N = 3e5 + 100;
ll len, f[N];
string s;
ll l, i, k;

ll qp(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x;
      res %= mod;
    }
    x = x * x;
    x %= mod;
    y >>= 1;
  }
  return res % mod;
}

int main() {
  ll tmp1 = 25 * qp(2, mod - 2);
  cout << tmp1 << endl;
  ll tmp2 =
      16 % mod + (qp(4 + 1, k) - qp(4, k) + mod) % mod * qp(2, mod - 2) % mod;
  cout << tmp2 << endl;

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> l >> k >> s;
  for (i = 1; i <= l; i++) {
    switch (s[i - 1]) {
    case '0':
      f[i] = f[i - 1];
      len = 0;
      break;
    case '1':
      f[i] = f[i - 1] % mod + (qp(len + 1, k) - qp(len, k) + mod) % mod;
      f[i] %= mod;
      len++;
      break;
    case '?':
      f[i] = f[i - 1] % mod +
             (qp(len + 1, k) - qp(len, k) + mod) % mod * qp(2, mod - 2) % mod;
      f[i] %= mod;
      len = (len + 1) % mod * qp(2, mod - 2) % mod;
      len %= mod;
      break;
    }
  }
  //	printf("%.4Lf",f[l]);
  printf("%lld", f[l]);
  return 0;
}
