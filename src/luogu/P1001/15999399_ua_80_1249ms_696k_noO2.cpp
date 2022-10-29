#include <cstdio>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  while (a--)
    b++;
  printf("%d", b);
  return 0;
}