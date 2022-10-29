#include <bits/stdc++.h>

using namespace std;

struct Node {
  vector<struct Edge> edges;
  bool pos;
  double dis;
} nodes[5010];

struct Edge {
  Node *from, *to;
  double w;
};

int n, m, x[5010], y[5010];

void add(int u, int v, double w) {
  Edge e;
  e.from = &nodes[u];
  e.to = &nodes[v];
  e.w = w;
  nodes[u].edges.push_back(e);
}

double prim(int s) {
  double ret = 0;
  set<pair<double, Node *>> heap;
  for (int i = 1; i <= n; ++i) {
    nodes[i].dis = 0x3f3f3f3f;
  }
  nodes[s].pos = 1;
  nodes[s].dis = 0;
  for (int i = 1; i <= n; ++i)
    heap.insert(make_pair(nodes[i].dis, &nodes[i]));
  while (heap.size() > 0) {
    double d = heap.begin()->first;
    Node *u = heap.begin()->second;
    heap.erase(heap.begin());
    if (d > u->dis)
      continue;
    u->pos = 1;
    for (int i = 0; i < (int)u->edges.size(); ++i) {
      if (!u->edges[i].to->pos && u->edges[i].w < u->edges[i].to->dis) {
        u->edges[i].to->dis = u->edges[i].w;
        heap.insert(make_pair(u->edges[i].to->dis, u->edges[i].to));
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    ret += nodes[i].dis;
  return ret;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    nodes[i].edges.reserve(10100);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      add(i, j, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)));
      add(j, i, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)));
    }
  printf("%.2lf", prim(1));
  return 0;
}