#include <cstdio>

int a[100010] = {0, 2, 7};
int n = 2;

int calc(int x) {
  if (x > n)
    return a[x];
  for (int i = n + 1; i <= x; ++i)
    a[i] = a[i - 1] + 4 * i - 2;
  return a[x];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", calc(x));
  }
  return 0;
}