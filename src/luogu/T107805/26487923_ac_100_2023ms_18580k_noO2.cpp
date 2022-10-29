#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w, nex;
} edges[4000010];

struct Node {
  int h, dis;
  bool vis;
} nodes[1000010];

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
    print(x % 10);
  putchar(x % 10 + '0');
}

int n, m, k, cnt;
int a[1000010];
bool b[1000010];

void addedge(int u, int v, int w) {
  edges[++cnt] = (struct Edge){v, w, nodes[u].h};
  nodes[u].h = cnt;
}

void dij(int s) {
  for (int i = 1; i <= n; ++i)
    nodes[i].dis = (int)1e9, nodes[i].vis = 0;
  nodes[s].dis = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      heap;
  heap.push(make_pair(nodes[s].dis, s));
  while (!heap.empty()) {
    int u = heap.top().second;
    heap.pop();
    if (nodes[u].vis)
      continue;
    nodes[u].vis = 1;
    for (int i = nodes[u].h; i; i = edges[i].nex)
      if (nodes[u].dis + edges[i].w < nodes[edges[i].v].dis) {
        nodes[edges[i].v].dis = nodes[u].dis + edges[i].w;
        if (!nodes[edges[i].v].vis)
          heap.push(make_pair(nodes[edges[i].v].dis, edges[i].v));
      }
  }
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
    addedge(v, u, w);
  }
  k = read();
  for (int i = 1; i <= k; ++i)
    a[i] = read(), b[a[i]] = 1;
  dij(a[1]);
  int maxn, maxd = -1;
  for (int i = 1; i <= n; ++i)
    if (b[i] && nodes[i].dis > maxd && nodes[i].dis != (int)1e9)
      maxn = i, maxd = nodes[i].dis;
  dij(maxn), maxd = -1;
  for (int i = 1; i <= n; ++i)
    if (b[i] && nodes[i].dis > maxd && nodes[i].dis != (int)1e9)
      maxn = i, maxd = nodes[i].dis;
  printf("%d\n", maxd);
  return 0;
}