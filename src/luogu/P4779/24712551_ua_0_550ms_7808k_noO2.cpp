#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w, nex;
} edges[200010];

struct Node {
  int dis, head;
} nodes[100010];

int n, m, s, cnt;

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

void addedge(int u, int v, int w) {
  edges[++cnt] = (Edge){v, w, nodes[u].head};
  nodes[u].head = cnt;
}

void dij(int start) {
  for (int i = 1; i <= n; ++i)
    nodes[i].dis = 63;
  set<pair<int, int>> heap;

  nodes[start].dis = 0;
  for (int i = 1; i <= n; ++i)
    heap.insert(make_pair(nodes[i].dis, i));
  while (heap.size() > 0) {
    int d = heap.begin()->first;
    int u = heap.begin()->second;
    heap.erase(heap.begin());
    if (d > nodes[u].dis)
      continue;
    for (int i = nodes[u].head; i != -1; i = edges[i].nex)
      if (nodes[u].dis + edges[i].w < nodes[edges[i].v].dis) {
        nodes[edges[i].v].dis = nodes[u].dis + edges[i].w;
        heap.insert(make_pair(nodes[edges[i].v].dis, edges[i].v));
      }
  }
}

int main() {
  n = read(), m = read(), s = read();
  for (int i = 0; i <= m + n; ++i)
    nodes[i].head = -1;
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
  }
  dij(s);
  for (int i = 1; i <= n; ++i)
    printf("%d ", nodes[i].dis);
  return 0;
}