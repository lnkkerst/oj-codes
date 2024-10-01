#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>

int n, m, a[23333];

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
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (int i = 1; i <= m; ++i) {
    std::next_permutation(a + 1, a + n + 1);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}
