#include <algorithm>
#include <cstdio>
#define ll long long

ll n, ans = 1, a[999999];

int main() {
  scanf("%lld", &n);

  while (n > 0) {
    if (n % 2 == 0) {
      a[ans] = n / 2;
    } else {
      a[ans] = n / 2 + 1;
    }
    n >>= 1;
    ++ans;
  }
  --ans;
  std::sort(a + 1, a + ans + 1);
  printf("%lld\n", ans);
  for (int i = 1; i <= ans; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}
