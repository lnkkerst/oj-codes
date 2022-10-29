#include <cctype>
#include <cstdio>

int n, sum, a[1010];

int read() {
  int ret;
  char ch;
  bool f;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return f ? -ret : ret;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
  return;
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      if (a[j] > a[i])
        ++sum;
  print(sum);
  return 0;
}