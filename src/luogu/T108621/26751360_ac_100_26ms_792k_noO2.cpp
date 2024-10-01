#include <bits/stdc++.h>
#define ll long long
const int mod = 1e9 + 7;
ll fpow(ll a, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1) {
      ret *= a;
      ret %= mod;
    }
    k >>= 1;
    a = a * a;
    a %= mod;
  }
  return ret % mod;
}
inline ll inv(int x) {
  return fpow(x, mod - 2);
}
int main() {
  using namespace std;
  ll n, k;
  cin >> n >> k;
  ll ans = fpow(n - 1, k - 1);
  ans -= fpow(-1, k - 1);
  ans %= mod;
  ans *= n - 1;
  ans %= mod;
  ans *= inv(n);
  ans %= mod;
  cout << (ans * inv(fpow(n - 1, k))) % mod;
}
