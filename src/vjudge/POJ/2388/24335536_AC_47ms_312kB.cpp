#include <algorithm>
#include <cctype>
#include <cstdio>

int n, a[10010];

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (fl = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * fl;
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
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  std::sort(a + 1, a + n + 1);
  if (n & 1) {
    print(a[(n + 1) >> 1]);
  } else {
    print((a[n >> 1] + a[n >> 1 & 1]) >> 1);
  }
  return 0;
}
