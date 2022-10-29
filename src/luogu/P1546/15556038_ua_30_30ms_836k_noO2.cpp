#include <algorithm>
#include <cstdio>
#define MAXN 10086

int n, ans;
int fa[MAXN], top = 0;
;

struct Edge {
  int u;
  int v;
  int w;
} e[MAXN];

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int father(int x) {
  if (fa[x] == x)
    return x;
  return fa[x] = father(fa[x]);
}

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int tmp;

      scanf("%d", &tmp);

      if (i != j && j >= i + 1) {
        e[++top].u = i;
        e[top].v = j;
        e[top].w = tmp;
      }
    }

  std::sort(e + 1, e + top + 1, cmp);

  for (int i = 1; i <= top; i++)
    fa[i] = i;

  for (int i = 1; i <= n; i++) {
    int x = father(e[i].u);
    int y = father(e[i].v);

    if (x == y)
      continue;

    fa[x] = y;
    ans += e[i].w;
  }

  printf("%d", ans);
  return 0;
}