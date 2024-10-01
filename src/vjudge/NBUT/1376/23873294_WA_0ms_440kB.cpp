#include <cctype>
#include <cstdio>

int a[110], n, x;
bool fl = 1;

inline int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

inline void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  while (scanf("%d", &n) != EOF) {
    int min = 9999, max = -1;
    for (register int i = 0; i <= 100; ++i) {
      a[i] = 0;
    }
    for (register int i = 1; i <= n; ++i) {
      x = read(), ++a[x], min = x < min ? x : min, max = x > max ? x : max;
    }
    for (register int i = min; i <= max; ++i) {
      while (a[i]--) {
        print(i);
        if (!(a[i] == 0 && i == max)) {
          putchar(' ');
        }
      }
    }
    putchar('\n');
  }
  return 0;
}
