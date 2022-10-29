#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXS = 2333, MOD = 1e9 + 7;

struct Mat {
  int n, m, data[MAXS][MAXS];
  Mat(int _n = 0, int _m = 0) {
    if (!_m)
      _m = _n;
    n = _n, m = _m;
    memset(data, 0, sizeof(data));
  }
  int *operator[](int x) { return data[x]; }
  Mat operator*(Mat b) {
    Mat ret(n, b.m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= b.m; ++j)
        for (int k = 1; k <= m; ++k)
          ret[i][j] = (ret[i][j] % MOD + data[i][k] * b[k][j] % MOD) % MOD;
    return ret;
  }
  Mat pow(int k) {
    Mat tmp(n), ret(n);
    for (int i = 1; i <= n; ret[i][i] = 1, ++i)
      for (int j = 1; j <= n; tmp[i][j] = data[i][j], ++j)
        ;
    while (k) {
      if (k & 1)
        ret = ret * tmp;
      tmp = tmp * tmp, k >>= 1;
    }
    return ret;
  }
};

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int n;

#undef int
int main() {
#define int long long
  n = read();
  Mat a(n, n), b(n, n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      a[i][j] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      b[i][j] = read();
  a = a * b;
  for (int i = 1; i <= n; ++i, putchar('\n'))
    for (int j = 1; j <= n; ++j)
      print(a[i][j]), putchar(' ');
}