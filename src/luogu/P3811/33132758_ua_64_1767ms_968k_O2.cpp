#include <cstdio>
#include <iostream>
#define int long long
using namespace std;

int qpow(int x, int k, int p) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret *= x;
    x *= x, k >>= 1;
    ret %= p, x %= p;
  }
  return ret;
}

signed main() {
  int n, p;
  scanf("%lld%lld", &n, &p);
  for (int i = 1; i <= n; ++i)
    printf("%lld\n", qpow(i, p - 2, p) % p);
  return 0;
}