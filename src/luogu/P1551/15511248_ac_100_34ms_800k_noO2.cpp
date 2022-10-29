#include <cstdio>

const int MAXN = 500010;

int f[MAXN];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
  int n, m, p;

  scanf("%d%d%d", &n, &m, &p);

  for (int i = 1; i <= n; i++)
    f[i] = i;

  int x, y;

  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    f[find(x)] = find(y);
  }

  for (int i = 1; i <= p; i++) {
    scanf("%d%d", &x, &y);

    if (find(x) == find(y))
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}