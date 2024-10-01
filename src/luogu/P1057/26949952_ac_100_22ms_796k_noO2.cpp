#include <cctype>
#include <cstdio>

int n, m, f[233][233] = {1};

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

int main() {
  n = read(), m = read();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (f[i][j]) {
        f[i + 1][(j - 1 + n) % n] += f[i][j], f[i + 1][(j + 1) % n] += f[i][j];
      }
    }
  }
  print(f[m][0]);
  return 0;
}
