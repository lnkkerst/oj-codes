#include <cstdio>

int main() {
  int n, m, tree[500010] = {0};

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    int a;

    scanf("%d", &a);

    for (int j = i; j <= n; j += j & -j)
      tree[j] += a;
  }

  for (int k = 1; k <= m; k++) {
    int e;

    scanf("%d", &e);

    if (e == 1) {
      int x, y, k;

      scanf("%d%d%d", &x, &y, &k);

      for (int i = x; i <= y; i++)
        for (int j = i; j <= n; j += j & -j)
          tree[j] += k;
    } else {
      int x, tmpx = 0, tmpy = 0;

      scanf("%d", &x);

      for (int j = x; j; j -= j & -j)
        tmpy += tree[j];

      for (int j = x - 1; j; j -= j & -j)
        tmpx += tree[j];

      printf("%d\n", tmpy - tmpx);
    }
  }

  return 0;
}