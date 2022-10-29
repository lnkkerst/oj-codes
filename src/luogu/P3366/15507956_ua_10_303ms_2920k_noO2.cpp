#include <algorithm>
#include <cstdio>
#define MAXN 200010

int n, m, ans;
int f[MAXN];

struct Edge {
  int u;
  int v;
  int w;
} e[MAXN];

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find(int x) {
  if (f[x] == x)
    return x;

  return f[x] = find(f[x]);
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

  std::sort(e + 1, e + m + 1, cmp);

  for (int i = 1; i <= n; i++)
    f[i] = i;

  for (int i = 1; i <= n; i++) {
    int x = find(e[i].u);
    int y = find(e[i].v);

    if (x == y)
      continue;

    f[x] = y;
    ans += e[i].w;
  }

  printf("%d", ans);

  return 0;
}