#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 100010
#define MAXM 200010

int n, m, s;

struct Node {
  std::vector<struct Edge> edges;
  bool visited = 0;
  bool inQueue = 0;
  int inDegree = 0;
  int dist;
  int dfn;
  int dfnOut;
} nodes[MAXN + 1];

struct Edge {
  Node *from, *to;
  int w;
};

void add(int u, int v, int w) {
  Edge e;
  e.from = &nodes[u];
  e.to = &nodes[v];
  ++nodes[v].inDegree;
  e.w = w;
  nodes[u].edges.push_back(e);
}

void dijkstra(int start) {
  for (int i = 1; i <= n; i++)
    nodes[i].dist = __INT_MAX__;

  std::priority_queue<std::pair<int, Node *>> q;

  q.push(std::make_pair(0, &nodes[start]));
  nodes[start].dist = 0;

  while (!q.empty()) {
    std::pair<int, Node *> p = q.top();
    q.pop();

    if (-p.first != p.second->dist)
      continue;
    Node *v = p.second;

    for (int i = 0; i < (int)v->edges.size(); i++) {
      Edge *e = &v->edges[i];
      if (e->to->dist > v->dist + e->w) {
        e->to->dist = v->dist + e->w;
        q.push(std::make_pair(-e->to->dist, e->to));
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= m; i++) {
    int t1, t2, t3;
    scanf("%d%d%d", &t1, &t2, &t3);
    add(t1, t2, t3);
  }
  dijkstra(s);
  for (int i = 1; i <= n; i++)
    printf("%d ", nodes[i].dist);
  return 0;
}