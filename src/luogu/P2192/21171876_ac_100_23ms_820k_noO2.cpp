#include <algorithm>
#include <cctype>
#include <cstdio>

int read() {
  int res;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = true);
  for (res = ch - '0'; isdigit(ch = getchar()); res = res * 10 + ch - '0')
    ;
  (flag) && (res = -res);
  return res;
}

void print(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int n = read();
  int t0 = 0, t5 = 0;
  while (n--)
    read() == 5 ? ++t5 : ++t0;
  if (!t0)
    print(-1);
  else if (t5 >= 9) {
    for (int i = 1; i <= t5 / 9 * 9; putchar('5'), ++i)
      ;
    for (int i = 1; i <= t0; putchar('0'), ++i)
      ;
  } else
    putchar('0');
  return 0;
}