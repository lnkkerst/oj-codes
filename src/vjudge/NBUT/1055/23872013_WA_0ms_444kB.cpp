#include <cctype>
#include <cstdio>

int a[] = {0, 1, 2, 11, 101, 111, 1001};
int l, r;
bool fl = 0;

int main() {
  while (scanf("%d%d", &l, &r) != EOF) {
    for (int i = 0; i < 7; ++i) {
      if (a[i] >= l && a[i] <= r) {
        printf("%d ", a[i]), fl = 1;
      }
    }
    if (!fl) {
      printf("-1\n");
    }
    putchar('\n');
  }
  return 0;
}
