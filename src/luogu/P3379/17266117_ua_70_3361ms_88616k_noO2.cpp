#include <cctype>
#include <cstdio>
#include <vector>
#define num ch - '0'
#define MAXN 500050

int n, m, s;

struct Node {
  std::vector<struct Edge> edges;
  bool visited;
  bool inQueue;
  int inDegree;
  int dist;
  int dfn;
  int dfnOut;
} nodes[MAXN + 1];

struct Edge {
  Node *from, *to;
  // int w;
};

void add(int u, int v) {
  Edge e;
  e.from = &nodes[u];
  e.to = &nodes[v];
  ++nodes[v].inDegree;
  // e.w = w;
  nodes[u].edges.push_back(e);
}

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

int fa[MAXN][20], logn;

void dfslca(Node *v) {
  static int timeStamp = 0;

  v->dfn = ++timeStamp;
  for (int i = 0; i < (int)v->edges.size(); i++) {
    Edge *e = &v->edges[i];
    if (!e->to->dfn) {
      fa[e->to - nodes][0] = v - nodes;
      dfslca(e->to);
    }
  }
  v->dfnOut = ++timeStamp;
}

void binaryLift(int root) {
  fa[root][0] = root;

  while ((1 << (logn + 1)) <= n) {
    logn++;
  }
  for (int j = 1; j <= logn; j++) {
    for (int i = 1; i <= n; i++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
  }
}

bool isAncestor(int ancestor, int child) {
  return nodes[ancestor].dfn < nodes[child].dfn
         && nodes[ancestor].dfnOut > nodes[child].dfnOut;
}

int lca(int u, int v) {
  if (u == v) {
    return u;
  }
  if (isAncestor(u, v)) {
    return u;
  }
  if (isAncestor(v, u)) {
    return v;
  }
  for (int j = logn; j >= 0; j--) {
    if (!isAncestor(fa[u][j], v)) {
      u = fa[u][j];
    }
  }
  return fa[u][0];
}

int main() {
  n = read();
  m = read();
  s = read();
  for (int i = 1; i <= n - 1; ++i) {
    int t1 = read(), t2 = read();
    add(t1, t2);
    add(t2, t1);
  }
  dfslca(&nodes[s]);
  binaryLift(s);
  for (int i = 1; i <= m; ++i) {
    int t1 = read();
    int t2 = read();
    print(lca(t1, t2));
    putchar('\n');
  }

  return 0;
}
