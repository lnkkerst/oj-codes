#include <iostream>
#define int long long
using namespace std;

int jc(int x) {
  int ret = 1;
  for (int i = 1; i <= x; ++i) {
    ret *= i;
  }
  return ret;
}

int C(int x, int n) {
  int t1 = 1, t2 = 1;
  if (x < n - x) {
    x = n - x;
  }
  for (int i = x + 1; i <= n; ++i) {
    t1 *= i;
  }
  for (int i = 1; i <= n - x; ++i) {
    t2 *= i;
  }
  return t1 / t2;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i, j, k;
    bool fl = 1;
    for (i = 1; i <= 100 && fl; ++i) {
      for (j = 2; j <= 100000 && fl; ++j) {
        for (k = 1; k <= 100 && fl; ++k) {
          if (i * C(2, j) * k == n) {
            fl = 0;
            while (i--) {
              cout << 1;
            }
            while (j--) {
              cout << 3;
            }
            while (k--) {
              cout << 7;
            }
            break;
          }
        }
      }
    }
    puts("");
  }
  return 0;
}
