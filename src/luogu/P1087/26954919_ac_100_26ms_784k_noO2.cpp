#include <algorithm>
#include <cctype>
#include <cstdio>

char s[10010];

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

void solve(int u, int v) {
  int mid = (u + v) >> 1;
  if (u != v) {
    solve(u, mid);
    solve(mid + 1, v);
  }
  int tmp1 = 0, tmp2 = 0;
  for (int i = u; i <= v; ++i)
    s[i] == 48 ? ++tmp1 : ++tmp2;
  if (tmp1 && tmp2)
    putchar('F');
  else if (tmp1)
    putchar('B');
  else
    putchar('I');
}

int main() {
  int n = read();
  scanf("%s", s + 1);
  solve(1, 1 << n);
  return 0;
}