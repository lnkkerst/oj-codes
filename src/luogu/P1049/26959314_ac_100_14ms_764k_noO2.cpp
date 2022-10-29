#include <algorithm>
#include <cctype>
#include <cstdio>

int n, m;
int f[1000010], w[1010];

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
  m = read(), n = read();
  for (int i = 1; i <= n; ++i)
    w[i] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = m; j >= w[i]; --j)
      if (f[j] < f[j - w[i]] + w[i])
        f[j] = f[j - w[i]] + w[i];
  print(m - f[m]);
  return 0;
}