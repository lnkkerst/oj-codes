#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define int long long
using namespace std;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int n, m, a[550][550];
int ans = -1;

signed main() {
  m = read(), n = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      a[i][j] = a[i - 1][j] + read();
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) {
      int sum = 0;
      for (int k = 1; k <= m; ++k)
        sum += a[j][k] - a[i - 1][k], sum = max(sum, 0ll), ans = max(sum, ans);
    }
  return print(ans), 0;
}