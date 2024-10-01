#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

int n, m;
const int MOD = (int)1e9 + 7;
int jc[200010] = {1};

int qpow(int x, int k, int p) {
  int ret = 1;
  while (k) {
    if (k & 1) {
      ret *= x;
    }
    x *= x, k >>= 1;
    x %= p, ret %= p;
  }
  return ret;
}

// int inv(int x, int p) {
// 	return qpow(x, p - 2, p);
// }

void exgcd(int a, int b, int &x, int &y, int &d) {
  if (!b) {
    d = a, x = 1, y = 0;
  } else {
    exgcd(b, a % b, y, x, d), y -= (a / b) * x;
  }
}

int inv(int a, int p) {
  int x, y, d;
  exgcd(a, p, x, y, d);
  return d == 1 ? (x % p + p) % p : -1;
}

int C(int n, int m) {
  return jc[n] * inv(jc[m], MOD) % MOD * inv(jc[n - m], MOD) % MOD;
}

signed main() {
  for (int i = 1; i < 200010; ++i) {
    jc[i] = (jc[i - 1] * i) % MOD;
  }
  cin >> n >> m;
  cout << C(n + m - 4, m - 2);
  return 0;
}
