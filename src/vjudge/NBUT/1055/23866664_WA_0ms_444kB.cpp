#include <cstdio>

int a[] = {0, 1, 2, 11, 101, 111, 1001};
int l, r;

int main() {
  while (scanf("%d%d", &l, &r) != EOF) {
    for (int i = 0; i < 7; ++i) {
      if (a[i] >= l && a[i] <= r) {
        printf("%d ", a[i]);
      }
    }
    putchar('\n');
  }
  return 0;
}
