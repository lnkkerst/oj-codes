#include <bits/stdc++.h>

using namespace std;

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

bool a[1000010];

int main() {
  for (int t = read(); t--;) {
    memset(a, 0, sizeof(a));
    int n = read(), k = read();
    for (int i = 1; i <= k; ++i)
      a[read()] = 1;
    int f = 0;
    for (int i = 2; i <= n; ++i) {
      if (!a[i] && (n % i)) {
        f = 1;
        break;
      }
    }
    if (f || !a[1])
      printf("%d\n", n);
    else
      printf("-1\n");
  }
  return 0;
}