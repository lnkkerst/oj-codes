#include <cstdio>
#include <hash_map>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    bool fl = 1;
    if (n > 1000000) {
      for (int i = 1000; i >= 10; --i) {
        int t = i * (i - 1) >> 1;
        if (n / t * t == n) {
          fl = 0;
          for (int j = 1; j <= n / t; ++j) {
            putchar('1');
          }
          for (int j = 1; j <= i; ++j) {
            putchar('3');
          }
          puts("7");
          break;
        }
      }
    }
    if (fl) {
      while (n--) {
        putchar('1');
      }
      puts("337");
    }
  }
  return 0;
}
