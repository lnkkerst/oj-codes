#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>

int n, ans;

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
  n = read();
  for (int i = 1, j; i <= n; i = j + 1) {
    j = n / (n / i);
    ans += (n / i) * (j - i + 1);
  }
  print(ans);
  return 0;
}
