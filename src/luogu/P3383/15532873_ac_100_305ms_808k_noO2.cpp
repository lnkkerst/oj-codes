#include <cmath>
#include <cstdio>

int m, n;

bool pd(int a) {
  if (a == 1) {
    return 0;
  }

  if (a == 2 || a == 3) {
    return 1;
  }

  if (a % 6 != 1 && a % 6 != 5) {
    return 0;
  }

  for (int i = 5; i <= sqrt(a); i += 6) {
    if (a % i == 0 || a % (i + 2) == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; i++) {
    int x;

    scanf("%d", &x);

    if (pd(x)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
