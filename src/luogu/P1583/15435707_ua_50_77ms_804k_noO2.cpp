#include <algorithm>
#include <cstdio>

const int MAXN = 20000 + 5;

struct p {
  int m;
  int w;
} a[MAXN];

bool cmp(p a, p b) {
  if (a.w == b.w) {
    return a.m < b.m;
  }

  return a.w > b.w;
}

int main() {
  int n, k, e[11];

  scanf("%d%d", &n, &k);

  for (int i = 1; i <= 10; i++) {
    scanf("%d", e + i);
  }

  for (int i = 1; i <= n; i++) {
    a[i].m = i;
    scanf("%d", &a[i].w);
  }

  std::sort(a + 1, a + n + 1, cmp);

  for (int i = 1; i <= n; i++) {
    a[i].w += e[i % 10];
  }

  std::sort(a + 1, a + n + 1, cmp);

  for (int i = 1; i <= k; i++) {
    printf("%d ", a[i].m);
  }

  return 0;
}
