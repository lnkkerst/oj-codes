#include <cstdio>

int a[110], n, x;
bool fl = 1;

int main() {
  while (scanf("%d", &n) != EOF) {
    int min = 9999, max = -1;
    for (int i = 0; i <= 100; ++i) {
      a[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x), ++a[x], min = x < min ? x : min, max = x > max ? x : max;
    }
    for (int i = min; i <= max; ++i) {
      while (a[i]--) {
        printf("%d", i);
        if (!(a[i] == 0 && i == max)) {
          putchar(' ');
        }
      }
    }
    putchar('\n');
  }
  return 0;
}
