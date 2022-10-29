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

int inv[3000010];

signed main() {
  int n, p;
  cin >> n >> p;
  inv[1] = 1;
  puts("1");
  for (int i = 2; i <= n; ++i)
    cout << (inv[i] = (p - p / i) * inv[p % i] % p) << endl;
  return 0;
}