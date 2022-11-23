#include <iostream>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int fastPow(int x, int k, int p = mod) {
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

signed main() {
  int n;
  cin >> n;
  cout << (fastPow(4, n - 1) * 3 / 4) << endl;
  return 0;
}
