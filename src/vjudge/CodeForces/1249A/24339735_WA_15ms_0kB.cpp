#include <cctype>
#include <cstdio>
#include <cstring>

bool b[101][101];
int q, n, a[101];

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (fl = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * fl;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x *= -1;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  q = read();
  while (q--) {
    n = read();
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) {
      int x = read();
      int pos = 1;
      while (b[pos][x] || b[pos][x - 1] || b[pos][x + 1])
        ++pos;
      b[pos][x] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= 100; ++i) {
      bool fl = 0;
      for (int j = 1; j <= 100; ++j)
        if (b[i][j]) {
          ++ans, fl = 1;
          break;
        }
      if (!fl)
        break;
    }
    print(ans), putchar('\n');
  }
  return 0;
}