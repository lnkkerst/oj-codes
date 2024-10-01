#include <algorithm>
#include <cctype>
#include <cstdio>
#define num ch - '0'
int read() {
  int res;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = true);
  }
  for (res = num; isdigit(ch = getchar()); res = res * 10 + num)
    ;
  (flag) && (res = -res);
  return res;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}
int n, a[1100], ans;
int main() {
  n = read();

  for (int i = 1; i <= n; i++) {
    for (int j = n - i + 1; j <= n; j++) {
      a[j] = std::max(a[j], a[j + 1]) + read();
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, a[i]);
  }
  print(ans);
  return 0;
}
