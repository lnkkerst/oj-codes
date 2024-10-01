#include <algorithm>
#include <cctype>
#include <cstdio>
#define num ch - '0'
int read() {
  int res;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
  for (res = num; isdigit(ch = getchar()); res *= 10, res += num)
    ;
  (flag == 1) && (res *= -1);
  return res;
}
int main() {
  int n = read(), t = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    t += read() + read() - 8, ans += t;
  }
  printf("%d\n", ans);
  return 0;
}
