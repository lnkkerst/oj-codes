#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2333;

int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

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

int n;

#undef int
int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      a[i][j] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      b[i][j] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        c[i][j] += a[i][k] * b[k][j];
  for (int i = 1; i <= n; ++i, putchar('\n'))
    for (int j = 1; j <= n; ++j)
      print(c[i][j]), putchar(' ');
  return 0;
}