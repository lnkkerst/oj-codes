#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

int a[100010], f1[100010], f2[100010], sum[100010];
int n;

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

int main() {
  while (233) {
    n = read();
    if (!n)
      return 0;
    for (int i = 1; i <= n; ++i)
      a[i] = read();
    int maxn = (int)1e9;
    f1[1] = a[1], f2[n] = sum[n] = a[n];
    for (int i = 2; i <= n; ++i)
      f1[i] = max(a[i], f1[i - 1] + a[i]);
    for (int i = n - 1; i >= 1; --i)
      f2[i] = max(a[i], f2[i + 1] + a[i]);
    for (int i = n - 1; i >= 1; --i)
      sum[i] = max(sum[i + 1], f2[i]);
    int summ = (int)1e9 * -1;
    for (int i = 2; i <= n; ++i)
      summ = max(summ, f1[i - 1] + sum[i]);
    print(summ), putchar('\n');
  }
  return 0;
}