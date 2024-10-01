#include <cctype>
#include <cstdio>

int n, m;
int a[23333];
int f[23333][23333];

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

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  f[1][1] = a[1];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= min(i, m); ++j) {
      if (!j) {
        f[i][0] = max(f[i][0], f[i - 1][0]);
      } else {
        f[i + j][0] = max(f[i + j][0], f[i][j]);
      }
      f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + a[i + 1]);
    }
  }
  print(f[n][0]);
  return 0;
}
