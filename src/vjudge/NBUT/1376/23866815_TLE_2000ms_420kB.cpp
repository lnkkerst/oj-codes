#include <cctype>
#include <cstdio>

int a[110], n, x;

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
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < 101; ++i)
      a[i] = 0;
    for (int i = 1; i <= n; ++i)
      ++a[read()];
    for (int i = 0; i < 101; ++i)
      while (a[i]--)
        print(i), putchar(' ');
    putchar('\n');
  }
  return 0;
}