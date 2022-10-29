#include <cctype>
#include <cstdio>

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
  int x1 = read(), x2 = read(), x3 = read(), x4 = read();
  int a = (int)((long long)x1 + x2 - x3) >> 1, b = x2 - a, c = x3 - b;
  printf("%d %d %d\n", a, b, c);
  return 0;
}