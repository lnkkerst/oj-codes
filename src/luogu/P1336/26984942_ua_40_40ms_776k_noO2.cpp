#include <cctype>
#include <cstdio>

int n, m;
int a[233], b[233];
int f[233][233];

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

int min(int x, int y) {
  return x < y ? x : y;
}

int qpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) {
      ret *= x;
    }
    x *= x;
    k >>= 1;
  }
  return ret;
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    a[i] = read(), b[i] = read();
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k <= j; ++k) {
        int tmp = a[i] * qpow(k, b[i]);
        if (f[i][j] == 0 || i == 1) {
          f[i][j] = f[i - 1][j - k] + tmp;
        } else {
          f[i][j] = min(f[i][j], f[i - 1][j - k] + tmp);
        }
      }
    }
  }
  print(f[m][n]);
  return 0;
}
