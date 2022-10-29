#include <algorithm>
#include <cstdio>

bool cmp(int a, int b) { return a > b; }

int main() {
  int n;
  scanf("%d", &n);
  int a[21] = {0};
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  std::sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++)
    printf("%d", a[i]);
  return 0;
}