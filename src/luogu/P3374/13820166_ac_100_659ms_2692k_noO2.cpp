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

  for (int i = 1; i <= m; i++) {
    int t, x, y;

    scanf("%d%d%d", &t, &x, &y);

    if (t == 1)
      for (int j = x; j <= n; j += j & -j)
        tree[j] += y;
    else {
      int tmpx = 0, tmpy = 0;

      for (int j = y; j; j -= j & -j)
        tmpy += tree[j];

      for (int j = x - 1; j; j -= j & -j)
        tmpx += tree[j];

      printf("%d\n", tmpy - tmpx);
    }
  }

  return 0;
}