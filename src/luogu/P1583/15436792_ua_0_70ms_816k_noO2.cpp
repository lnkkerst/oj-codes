#include <algorithm>
#include <cstdio>

const int MAXN = 20000 + 10;

struct p {
  int m;
  int w;
} a[MAXN];

bool cmp(p a, p b) {
  if (a.w == b.w)
    return a.m < b.m;

  return a.w > b.w;
}

int main() {
  int n, k, e[20];

  scanf("%d%d", &n, &k);

  for (int i = 0; i < 10; i++)
    scanf("%d", e + i);

  for (int i = 0; i < n; i++) {
    a[i].m = i + 1;
    scanf("%d", &a[i].w);
  }

  std::sort(a, a + n, cmp);

  for (int i = 1; i <= n; i++)
    a[i].w += e[i % 10 - 1];

  std::sort(a, a + n, cmp);

  for (int i = 0; i < k; i++)
    printf("%d ", a[i].m);

  return 0;
}