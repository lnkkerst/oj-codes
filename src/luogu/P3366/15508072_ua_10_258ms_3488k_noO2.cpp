#include <algorithm>
#include <cstdio>
#define MAXN 200010

int n, m, ans;
int fa[MAXN];

struct Edge {
  int f;
  int t;
  int w;
} e[MAXN];

bool operator<(Edge a, Edge b) {
  return a.w < b.w;
}

int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = find(fa[x]);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &e[i].f, &e[i].t, &e[i].w);
  }
  std::sort(e + 1, e + m + 1);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x = find(e[i].f);
    int y = find(e[i].t);
    if (x == y) {
      continue;
    }
    fa[x] = y;
    ans += e[i].w;
  }
  printf("%d", ans);
  return 0;
}
