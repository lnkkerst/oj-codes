#include <algorithm>
#include <cctype>
#include <cstdio>
#define MAXN 10010
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

int a[MAXN], ans = 0;

int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read() << 1;
  }
  while (m--) {
    int t1 = read(), t2 = read(), t3 = read();
    a[t1] += t3;
    a[t2] += t3;
  }
  std::stable_sort(a + 1, a + 1 + n);
  while (n) {
    ans += a[n--] - a[n--];
  }
  print(ans / 2);
  putchar('\n');
  return 0;
}
