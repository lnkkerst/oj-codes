#include <cstdio>

int a[110], n, x;

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i <= 100; ++i) {
      a[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x), ++a[x];
    }
    for (int i = 0; i <= 100; ++i) {
      while (a[i]--) {
        printf("%d ", i);
      }
    }
    putchar('\n');
  }
  return 0;
}
