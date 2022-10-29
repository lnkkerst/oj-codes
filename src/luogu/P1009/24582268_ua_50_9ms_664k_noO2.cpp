#include <cstdio>

int main() {
  long long n;
  scanf("%lld", &n);
  long long ans = 0, t = 1;
  for (long long i = 1; i <= n; ++i)
    ans += t *= i;
  printf("%lld", ans);
  return 0;
}