#include <bits/stdc++.h>

using namespace std;

int n, m, a[10086];

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (int k = 1; k <= m; ++k) {
    int l = read(), r = read(), l1 = read(), r1 = read(), ans = 0;
    for (int i = l; i <= r; ++i) {
      for (int j = l1; j <= r1; ++j) {
        ans += a[i] == a[j];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
