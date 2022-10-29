#include <cstdio>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    if (!(n & 1))
      printf("Alice\n");
    else {
      int tmp = 1;
      int f = 1;
      while (tmp < n) {
        tmp = tmp * 2 + 1;
        if (tmp == n)
          f = 0;
      }
      printf("%s\n", f ? "Alice" : "Bob");
    }
  }
  return 0;
}