#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define int __int128_t
using namespace std;

const int MOD = (int)1e9 + 7;
int n = 2;

struct Mat {
  int m[10][10];
  int *operator[](const int x) {
    return m[x];
  }
  Mat() {
    memset(m, 0, sizeof(m));
  }
};

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int mod(int x) {
  return (x % MOD + MOD) % MOD;
}

Mat mul(Mat a, Mat b) {
  Mat ret;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        ret[i][j] = mod(ret[i][j] + mod(a[i][k]) * mod(b[k][j]));
      }
    }
  }
  return ret;
}

signed main() {
  int f1 = read(), f2 = read(), x = read();
  Mat ans, base;
  ans[1][1] = f2, ans[1][2] = f1;
  base[1][1] = 1, base[2][1] = -1, base[1][2] = 1;
  x = max(x - 2, (__int128_t)0);
  while (x) {
    if (x & 1) {
      ans = mul(ans, base);
    }
    base = mul(base, base);
    x >>= 1;
  }
  print(mod(ans[1][1]));
  return 0;
}
