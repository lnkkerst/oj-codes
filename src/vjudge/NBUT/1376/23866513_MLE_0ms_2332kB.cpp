#include <algorithm>
#include <cctype>
#include <cstdio>

char a[2000010], n;

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    putchar('\n');
  }
  return 0;
}
