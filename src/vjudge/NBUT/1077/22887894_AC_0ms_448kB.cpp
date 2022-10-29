#include <cstdio>
#define int long long

int a[233] = {0, 1, 2};
int n = 2;

int calc(int x) {
  if (x <= n)
    return a[x];
  for (int i = n + 1; i <= x; ++i)
    a[i] = a[i - 1] + a[i - 2];
  return a[x];
}

signed main() {
  int x;
  while (scanf("%lld", &x) != EOF)
    printf("%lld\n", calc(x));
  return 0;
}