#include <iostream>
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

int main() {
  int n, p;
  cin >> n >> p;
  inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    inv[i] = (p - p / i) * inv[p % i] % p;
  for (int i = 1; i <= n; ++i)
    cout << inv[i] << endl;
  return 0;
}