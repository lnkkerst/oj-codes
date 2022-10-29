#include <cctype>
#include <cmath>
#include <cstdio>

int n, a[2333] = {1};

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
  n = read();
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 1; j < (1 << n) - i; ++j)
      printf(" ");
    for (int j = i; j >= 0; --j)
      a[j] ^= a[j - 1];
    if (!(i & 1))
      for (int j = 0; j <= i; ++j)
        printf("%s", a[j] ? "/\\" : "  ");
    else
      for (int j = 0; j <= i; j += 2)
        printf("%s", a[j] ? "/__\\" : "    ");
    puts("");
  }
  return 0;
}