#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
#define MAXN 2000010
using namespace std;

int n, m;
int st, ed;

struct Node {
  std::vector<struct Edge> edges;
  int dist;
} nodes[MAXN + 1];

struct Edge {
  Node *from, *to;
  int w;
};

void addedge(int u, int v, int w) {
  Edge e;
  e.from = &nodes[u];
  e.to = &nodes[v];
  e.w = w;
  nodes[u].edges.push_back(e);
}

int dijkstra(int start) {
  for (int i = 1; i <= n * m * 2; i++)
    nodes[i].dist = (int)1e9;
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
  return nodes[ed].dist;
}

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

signed main() {
  n = read(), m = read();
  st = (n - 1) * (m - 1) * 2 + 1, ed = (n - 1) * (m - 1) * 2 + 2;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m - 1; ++j) {
      int x = read();
      if (i == 1)
        addedge(st, j, x);
      else if (i == n)
        addedge((2 * (n - 1) - 1) * (m - 1) + j, ed, x);
      else
        addedge((2 * (i - 1) - 1) * (m - 1) + j, 2 * (i - 1) * (m - 1) + j, x);
    }
  for (int i = 1; i <= n - 1; ++i)
    for (int j = 1; j <= m; ++j) {
      int x = read();
      if (j == 1)
        addedge((i * 2 - 1) * (m - 1) + 1, ed, x);
      else if (j == m)
        addedge(st, 2 * i * (m - 1) - (m - 1), x);
      else
        addedge((i - 1) * 2 * (m - 1) + j - 1, ((i - 1) * 2 + 1) * (m - 1) + j,
                x);
    }
  for (int i = 1; i <= n - 1; ++i)
    for (int j = 1; j <= m - 1; ++j) {
      int x = read();
      addedge((i - 1) * 2 * (m - 1) + j, (i - 1) * 2 * (m - 1) + (m - 1) + j,
              x);
    }
  print(dijkstra(st));
  return 0;
}