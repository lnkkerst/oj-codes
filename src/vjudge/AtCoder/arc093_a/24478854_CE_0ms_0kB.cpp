#include <cctype>
#include <cmath>
#include <cstdio>

int n, a[100010], tot;

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (fl = -1);
  }
  ret = ch - '0';
  while (isdigit(ch = getchar())) {
    ret *= 10, ret += ch - '0';
  }
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
    a[i] = read(), tot += abs(a[i] - a[i - 1]);
  }
  tot += abs(a[n]);
  for (int i = 1; i <= n; ++i) {
    int ans;
    if (a[i] > a[i - 1]) {
      if (a[i + 1] > a[i]) {
        ans = tot;
      } else {
        if (a[i + 1] > a[i - 1]) {
          ans = tot + a[i + 1] * 2 - a[i] * 2;
        } else {
          ans = tot + a[i - 1] * 2 - a[i] * 2;
        }
      }
    } else {
      if (a[i + 1] < a[i]) {
        ans = tot;
      } else {
        if (a[i + 1] > a[i - 1]) {
          ans = tot + a[i] * 2 - a[i - 1] * 2;
        } else {
          ans = tot + a[i] * 2 - a[i + 1] * 2;
        }
      }
    }
    print(ans), putchar('\n');
  }
  return 0;
}
