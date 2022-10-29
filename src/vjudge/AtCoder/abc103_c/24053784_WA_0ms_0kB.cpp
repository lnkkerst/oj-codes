#include <cctype>
#include <cstdio>
#define int __int128

int n, tmp = 1, ans = 0;
int a[3010];

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

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

int lcm(int x, int y) { return x * y / gcd(x, y); }

signed main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  for (int i = 1; i <= n; ++i)
    tmp = lcm(tmp, a[i]);
  --tmp;
  for (int i = 1; i <= n; ++i)
    ans += tmp % a[i];
  print(ans);
}