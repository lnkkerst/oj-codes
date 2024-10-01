#include <cmath>
#include <cstdio>

int main() {
  int n;
  bool flag = 0;
  scanf("%d", &n);
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      flag = 1;
    }
  }

  !flag ? printf("YES\n") : printf("NO\n");

  return 0;
}
