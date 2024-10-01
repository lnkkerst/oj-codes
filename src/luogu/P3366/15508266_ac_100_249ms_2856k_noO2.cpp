#include <algorithm>
#include <cstdio>

const int MAXN = 10010;
const int MAXM = 200010;

int m, n, ans;
int fa[MAXN];

struct Edge {
  int u;
  int v;
  int w;
} e[MAXM];

bool cmp(Edge a, Edge b) {
  return a.w < b.w;
}

int father(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = father(fa[x]);
}

int main() {
  scanf("%d %d", &m, &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
  }

  std::sort(e + 1, e + n + 1, cmp);

  for (int i = 1; i <= m; i++) {
    fa[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    int x = father(e[i].u);
    int y = father(e[i].v);

    if (x == y) {
      continue;
    }

    fa[x] = y;
    ans += e[i].w;
  }

  printf("%d", ans);
  return 0;
}
