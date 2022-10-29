#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", 2 * x * x - x + 1);
  }
  return 0;
}