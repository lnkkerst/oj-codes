#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 10086
#define INF 0x7fffffff
#define num ch - '0'

struct Node {
  std::vector<struct Edge> edges;
  bool visited;
  bool inQueue;
  int inDegree;
  int dist;
  int dfn;
  int dfnOut;
  int cnt;
} nodes[MAXN + 1];

struct Edge {
  Node *from, *to;
  int w;
};

int f, m, n, z;

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

void add(int u, int v, int w) {
  Edge e;
  e.from = &nodes[u];
  e.to = &nodes[v];
  ++nodes[v].inDegree;
  e.w = w;
  nodes[u].edges.push_back(e);
}

bool spfa(int start) {
  for (int i = 1; i <= n; i++) {
    nodes[i].dist = INF;
  }

  std::queue<Node *> q;

  q.push(&nodes[start]);
  nodes[start].dist = 0;
  nodes[start].inQueue = 1;

  while (!q.empty()) {
    Node *v = q.front();
    q.pop();

    v->inQueue = 0;

    for (int i = 0; i < (int)v->edges.size(); i++) {
      Edge *e = &v->edges[i];
      if (e->to->dist > v->dist + e->w) {
        e->to->dist = v->dist + e->w;
        if (!e->to->inQueue) {
          e->to->inQueue = 0;
          q.push(e->to);
          e->to->cnt++;
        }
        if (e->to->cnt > n) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  f = read();
  while (f--) {
    n = read();
    m = read();
    z = read();
    for (int i = 1; i <= m; ++i) {
      int t1 = read(), t2 = read(), t3 = read();
      add(t1, t2, t3);
      add(t2, t1, t3);
    }
    for (int i = 1; i <= z; ++i) {
      int t1 = read(), t2 = read(), t3 = read();
      add(t1, t2, -t3);
    }
    if (spfa(1)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
