#include <cctype>
#include <cstdio>
#define int long long

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  if (ch == EOF) {
    return EOF;
  }
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

int count_zero(int x) {
  int ret = 0;
  while (x && !(x % 10)) {
    ++ret, x /= 10;
  }
  return ret;
}

int qpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) {
      ret *= x;
    }
    x *= x, k >>= 1;
  }
  return ret;
}

signed main() {
  int n = read(), k = read(), ans = n;
  while (count_zero(ans) < k) {
    ans += n;
  }
  print(ans);
  return 0;
}
