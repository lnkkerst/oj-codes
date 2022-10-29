#include <cstdio>

int main() {
  int t, s, x;
  scanf("%d%d%d", &t, &s, &x);
  int tmp = x - t;
  if (tmp % s == 0 || tmp % s == 1 && tmp > 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}