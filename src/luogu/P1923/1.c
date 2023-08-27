#include <stdio.h>
#include <stdlib.h>

#define MAXN 5000010

int a[MAXN], n, k;

int cmp(const void *a, const void *b) {
  int arg1 = *(const int *)a;
  int arg2 = *(const int *)b;
  if (arg1 < arg2) {
    return -1;
  }
  if (arg1 > arg2) {
    return 1;
  }
  return 0;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), cmp);
  printf("%d", a[k]);
}
