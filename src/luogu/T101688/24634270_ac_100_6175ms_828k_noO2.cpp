#include <algorithm>
#include <cstdio>

int n, a[13001], ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    int dp = a[i], maxdp = a[i];
    for (int j = i + 1; j <= n; ++j) {
      if (maxdp > 0) {
        ans += maxdp;
      }
      ans %= (int)1e5;
      dp = std::max(dp + a[j], a[j]);
      maxdp = std::max(maxdp, dp);
    }
    if (maxdp > 0) {
      ans += maxdp;
    }
    ans %= (int)1e5;
  }
  printf("%d\n", ans % (int)1e5);
  return 0;
}
