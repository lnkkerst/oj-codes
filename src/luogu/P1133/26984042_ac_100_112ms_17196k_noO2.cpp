#include <cctype>
#include <cstdio>

int n, ans;
int a[100010][6], f[100010][6][6];

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
    for (int j = 1; j <= 3; ++j) {
      a[i][j] = read();
    }
  }
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      f[1][0][j] = f[1][1][j] = 0;
    }
    f[1][1][i] = f[1][0][i] = a[1][i];
    for (int j = 2; j <= n; ++j) {
      f[j][0][2] = f[j - 1][1][1] + a[j][2];
      f[j][0][3] = max(f[j - 1][1][1], f[j - 1][1][2]) + a[j][3];
      f[j][1][1] = max(f[j - 1][0][2], f[j - 1][0][3]) + a[j][1];
      f[j][1][2] = f[j - 1][0][3] + a[j][2];
    }
    for (int j = 1; j < i; ++j) {
      ans = max(ans, f[n][1][j]);
    }
    for (int j = 3; j > i; --j) {
      ans = max(ans, f[n][0][j]);
    }
  }
  print(ans);
  return 0;
}
