#include <iostream>
#define int long long
using namespace std;

int qpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) {
      ret *= x;
    }
    x *= x, k >>= 1;
  }
  return ret;
}

int gcd(int x, int y) {
  return !y ? x : gcd(y, x % y);
}

signed main() {
  int a, b;
  while (cin >> a >> b) {
    int t = qpow(10, b);
    cout << a * t / gcd(t, a) << endl;
  }
  return 0;
}
