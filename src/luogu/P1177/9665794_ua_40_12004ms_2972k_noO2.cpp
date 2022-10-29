#include <cstdio>
using namespace std;
long a[100001];
void qsort(int l, int r) {
  int i = l, j = r, x = a[l];
  for (; i < j;) {
    for (; (i < j) && (a[j] >= x); j--)
      ;
    if (i < j) {
      a[i] = a[j];
      i++;
    }
    for (; (i < j) && (a[i] <= x); i++)
      ;
    if (i < j) {
      a[j] = a[i];
      j--;
    }
  }
  a[i] = x;
  if (l < i - 1)
    qsort(l, i - 1);
  if (r > i + 1)
    qsort(i + 1, r);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  qsort(1, n);
  for (int i = 1; i < n; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[n]);
  return 0;
}