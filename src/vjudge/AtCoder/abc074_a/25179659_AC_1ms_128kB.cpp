#include <ctype.h>
#include <stdio.h>

int read() {
  char ch;
  int ret, fl = 1;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (fl = -1);
  ret = ch - '0';
  while (isdigit(ch = getchar()))
    ret *= 10, ret += ch - '0';
  return ret * fl;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int n = read(), a = read();
  return print(n * n - a), 0;
}