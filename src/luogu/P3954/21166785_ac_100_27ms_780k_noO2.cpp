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

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() { print(read() * 2 / 10 + read() * 3 / 10 + read() * 5 / 10); }