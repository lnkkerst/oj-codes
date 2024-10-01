#include <cctype>
#include <cstdio>
#define int unsigned long long

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
  // if(x < 0) putchar('-'), x = -x;
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

void dfs(int n, int k, int fl) {
  if (n == 0ull) {
    return;
  }
  if (k >= (1ull << (n - 1ull))) {
    if (fl) {
      putchar('0');
    } else {
      putchar('1');
    }
    dfs(n - 1ull, k - (1ull << (n - 1ull)), 1ull);
  } else {
    if (fl) {
      putchar('1');
    } else {
      putchar('0');
    }
    dfs(n - 1ull, k, 0);
  }
  return;
}

signed main() {
  int n = read(), k = read();
  dfs(n, k, 0);
  return 0;
}
