#include <cstdio>

long long f[100] = {2, 1}, x;

int main() {
  scanf("%lld", &x);
  for (int i = 2; i <= x; ++i)
    f[i] = f[i - 1] + f[i - 2];
  printf("%lld\n", f[x]);
  return 0;
}