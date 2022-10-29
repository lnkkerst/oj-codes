#include <algorithm>
#include <cctype>
#include <cstdio>
#define int unsigned long long

int n, sum, a[100010], b[100010];

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
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

#undef int
int main() {
#define int unsigned long long
  n = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  std::sort(a + 1, a + n + 1);
  b[1] = a[1];
  for (int i = 2; i <= n; ++i)
    b[i] = b[i - 1] + a[i];
  for (int i = 1; i <= n - 1; ++i)
    sum += a[i + 1] * i - b[i];
  sum *= 2, sum += b[n];
  int tmp = gcd(sum, n);
  print(sum / tmp), putchar(' '), print(n / tmp);
  return 0;
}