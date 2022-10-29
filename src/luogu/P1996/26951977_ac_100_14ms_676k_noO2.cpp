#include <algorithm>
#include <cctype>
#include <cstdio>

int n, m, s;
bool vis[233];

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

int main() {
  n = read(), m = read();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      (++s > n) && (s = 1), (vis[s]) && (--j);
    print(s), putchar(' ');
    vis[s] = 1;
  }
  return 0;
}