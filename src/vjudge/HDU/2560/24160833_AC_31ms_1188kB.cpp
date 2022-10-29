#include <cctype>
#include <cstdio>

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
  int t = read();
  while (t--) {
    int n = read(), m = read(), ans = 0;
    for (int i = 1; i <= n * m; ++i)
      ans += read();
    print(ans), putchar('\n');
  }
  return 0;
}