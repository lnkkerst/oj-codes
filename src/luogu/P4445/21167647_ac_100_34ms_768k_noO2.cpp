#include <cctype>
#include <cstdio>

int read() {
  int res;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = true);
  }
  for (res = ch - '0'; isdigit(ch = getchar()); res = res * 10 + ch - '0')
    ;
  (flag) && (res = -res);
  return res;
}

void print(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n = read();
  long long ans = 0;
  int t = read();
  for (int i = 1; i < n; ++i) {
    int r = read();
    ans += max(t, r);
    t = r;
  }
  print(ans);
  return 0;
}
