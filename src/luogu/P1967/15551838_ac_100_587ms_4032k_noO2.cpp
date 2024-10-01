#include <algorithm>
#include <cstdio>

const int MAXN = 10010;
const int INF = 999999999;

struct Edge1 {
  int u;
  int v;
  int w;
} e1[50010];

struct Edge2 {
  int to;
  int next;
  int w;
} e2[100010];

int m, n, cnt, x, y, z, q;
int f[MAXN], deep[MAXN], head[MAXN], fa[MAXN][21], w[MAXN][21];
bool book[MAXN];

void swap(int &a, int &b) {
  int t;
  t = a;
  a = b;
  b = t;
}

int min(int a, int b) {
  return a < b ? a : b;
}

bool cmp(Edge1 a, Edge1 b) {
  return a.w > b.w;
}

int father(int x) {
  if (f[x] == x) {
    return f[x];
  }
  return f[x] = father(f[x]);
}

void add(int from, int to, int w) {
  e2[++cnt].next = head[from];
  e2[cnt].to = to;
  e2[cnt].w = w;
  head[from] = cnt;
  return;
}

void dfs(int node) {
  book[node] = 1;

  for (int i = head[node]; i; i = e2[i].next) {
    int to = e2[i].to;

    if (book[to]) {
      continue;
    }

    deep[to] = deep[node] + 1;
    fa[to][0] = node;
    w[to][0] = e2[i].w;

    dfs(to);
  }

  return;
}

int lca(int x, int y) {
  if (father(x) != father(y)) {
    return -1;
  }

  int ans = INF;

  if (deep[x] > deep[y]) {
    swap(x, y);
  }

  for (int i = 20; i >= 0; i--) {
    if (deep[fa[y][i]] >= deep[x]) {
      ans = min(ans, w[y][i]);
      y = fa[y][i];
    }
  }

  if (x == y) {
    return ans;
  }

  for (int i = 20; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) {
      ans = min(ans, min(w[x][i], w[y][i]));
      x = fa[x][i];
      y = fa[y][i];
    }
  }

  ans = min(ans, min(w[x][0], w[y][0]));

  return ans;
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e1[i].u, &e1[i].v, &e1[i].w);
  }

  std::sort(e1 + 1, e1 + m + 1, cmp);

  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    if (father(e1[i].u) != father(e1[i].v)) {
      f[father(e1[i].u)] = father(e1[i].v);
      add(e1[i].u, e1[i].v, e1[i].w);
      add(e1[i].v, e1[i].u, e1[i].w);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!book[i]) {
      deep[i] = 1;

      dfs(i);

      fa[i][0] = i;
      w[i][0] = INF;
    }
  }

  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= n; j++) {
      fa[j][i] = fa[fa[j][i - 1]][i - 1];
      w[j][i] = min(w[j][i - 1], w[fa[j][i - 1]][i - 1]);
    }
  }

  scanf("%d", &q);

  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    printf("%d\n", lca(x, y));
  }

  return 0;
}
