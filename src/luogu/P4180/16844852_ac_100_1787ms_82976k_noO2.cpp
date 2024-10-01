#include <algorithm>
#include <cctype>
#include <cstdio>
#define num ch - '0'
#define int long long

const int MAXN = 500000;
const int MAXM = 1000000;
const int INF = 2147483647000000;

struct Edge {
  int u;
  int v;
  int w;
  int next;
} e[MAXN << 1], ee[MAXN << 1];

int n, m, tot = 0, cnt = 0ll, ans = INF, fa[MAXN], head[MAXN], bz[MAXN][20],
          maxi[MAXN][20], mini[MAXN][19], deep[MAXN];
bool b[MAXN << 1];

int read() {
  int res;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = true);
  }
  for (res = num; isdigit(ch = getchar()); res = res * 10 + num)
    ;
  (flag) && (res = -res);
  return res;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int max(int x, int y) {
  return x > y ? x : y;
}

int min(int x, int y) {
  return x < y ? x : y;
}

void swap(int &x, int &y) {
  int t;
  t = x;
  x = y;
  y = t;
}

bool cmp(Edge a, Edge b) {
  return a.w < b.w;
}

void add(int u, int v, int w) {
  e[++tot].u = u;
  e[tot].v = v;
  e[tot].w = w;
  e[tot].next = head[u];
  head[u] = tot;
  e[++tot].u = v;
  e[tot].v = u;
  e[tot].w = w;
  e[tot].next = head[v];
  head[v] = tot;
}

void dfs(int u, int fa) {
  bz[u][0] = fa;

  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;

    if (v == fa) {
      continue;
    }

    deep[v] = deep[u] + 1ll;
    maxi[v][0] = e[i].w;
    mini[v][0] = INF * -1;
    dfs(v, u);
  }
}

int father(int x) {
  return fa[x] == x ? x : fa[x] = father(fa[x]);
}

void cal() {
  for (int i = 1; i <= 18; i++) {
    for (int j = 1; j <= n; j++) {
      bz[j][i] = bz[bz[j][i - 1]][i - 1];
      maxi[j][i] = max(maxi[j][i - 1], maxi[bz[j][i - 1]][i - 1]);
      mini[j][i] = max(mini[j][i - 1], mini[bz[j][i - 1]][i - 1]);

      if (maxi[j][i - 1] > maxi[bz[j][i - 1]][i - 1]) {
        mini[j][i] = max(mini[j][i], maxi[bz[j][i - 1]][i - 1]);
      } else if (maxi[j][i - 1] < maxi[bz[j][i - 1]][i - 1]) {
        mini[j][i] = max(mini[j][i], maxi[j][i - 1]);
      }
    }
  }
}

// int lca(int x, int y) {
//     if(father(x) != father(y))
//         return -1;

//     int ans = INF;

//     if(deep[x] > deep[y])
//         swap(x, y);

//     for(int i = 20; i >= 0; i--)
//         if(deep[fa[y][i]] >= deep[x]) {
//             ans = min(ans, w[y][i]);
//             y = fa[y][i];
//         }

//     if(x == y)
//         return ans;

//     for(int i = 20; i >= 0; i--)
//         if(fa[x][i] != fa[y][i]) {
//             ans = min(ans, min(w[x][i], w[y][i]));
//             x = fa[x][i];
//             y = fa[y][i];
//         }

//     ans = min(ans, min(w[x][0], w[y][0]));

//     return ans;
// }

int lca(int x, int y) {
  if (deep[x] < deep[y]) {
    swap(x, y);
  }

  for (int i = 18; i >= 0; i--) {
    if (deep[bz[x][i]] >= deep[y]) {
      x = bz[x][i];
    }
  }

  if (x == y) {
    return x;
  }

  for (int i = 18; i >= 0; i--) {
    if (bz[x][i] ^ bz[y][i]) {
      x = bz[x][i];
      y = bz[y][i];
    }
  }

  return bz[x][0];
}

int qmax(int u, int v, int maxx) {
  int ans = INF * -1;

  for (int i = 18; i >= 0; i--) {
    if (deep[bz[u][i]] >= deep[v]) {
      if (maxx != maxi[u][i]) {
        ans = max(ans, maxi[u][i]);
      } else {
        ans = max(ans, mini[u][i]);
      }
      u = bz[u][i];
    }
  }

  return ans;
}

int kruskal() {
  std::sort(ee + 1, ee + m + 1, cmp);

  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  int cnt = 0ll;
  for (int i = 1; i <= m; i++) {
    int tu = father(ee[i].u), tv = father(ee[i].v);

    if (tu != tv) {
      cnt += ee[i].w;
      fa[tu] = tv;
      add(ee[i].u, ee[i].v, ee[i].w);
      b[i] = 1;
    }
  }

  return cnt;
}

#undef int

int main() {
#define int long long

  n = read();
  m = read();

  for (int i = 1; i <= m; i++) {
    ee[i].u = read();
    ee[i].v = read();
    ee[i].w = read();
  }

  int cnt = kruskal();

  mini[1][0] = INF * -1;
  deep[1] = 1;
  dfs(1, -1);
  cal();

  int ans = INF;

  for (int i = 1; i <= m; i++) {
    if (!b[i]) {
      int u = ee[i].u;
      int v = ee[i].v;
      int w = ee[i].w;
      int lcat = lca(u, v);
      int maxu = qmax(u, lcat, w);
      int maxv = qmax(v, lcat, w);
      ans = min(ans, cnt - max(maxu, maxv) + w);
      // printf("%lld\n", cnt);
    }
  }

  printf("%lld", ans);

  return 0;
}
