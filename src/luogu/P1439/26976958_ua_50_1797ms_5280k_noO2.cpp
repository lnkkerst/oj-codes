#include <cctype>
#include <cstdio>

int f[1001][1001];
int n;
int a[100010], b[100010];

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

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (int i = 1; i <= n; ++i) {
    b[i] = read();
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i] == b[j]) {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]) + 1;
      } else {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      }
    }
  }
  print(f[n][n]);
  return 0;
}
