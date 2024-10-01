#include <algorithm>
#include <cctype>
#include <cstdio>

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  int a[5];
  for (int i = 1; i <= 4; ++i) {
    a[i] = read();
  }
  std::sort(a + 1, a + 5);
  printf("%d %d %d\n", a[4] - a[1], a[2] - (a[4] - a[1]), a[3] - (a[4] - a[1]));
  return 0;
}
