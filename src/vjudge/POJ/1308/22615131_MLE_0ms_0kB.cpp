#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>

int f, s, i;
bool b[233335333], ans = 1;

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
  while (233) {
    f = read(), s = read();
    if (f == -1)
      return 0;
    if (f == 0) {
      if (ans)
        printf("Case %d is a tree.\n", ++i);
      else
        printf("Case %d is not a tree.\n", ++i);
      ans = 1;
      memset(b, 0, sizeof(b));
      continue;
    }
    if (b[s])
      ans = 0;
    b[s] = 1;
  }
}