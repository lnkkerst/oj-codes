#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#define int long long
using namespace std;

struct Node {
  int h, dis[20];
  int d;
  bool vis;
  Node(int _h = 0, int _dis = (int)1e9, bool _vis = 0) {
    h = _h, dis[0] = _dis;
    vis = _vis;
  }
} nodes[100010];

struct Edge {
  int to, nex, w;
} edges[200010];

int n, m, s = 1, cnt = 0, k;

void addedge(int u, int v, int w) {
  edges[++cnt] = (Edge){v, nodes[u].h, w};
  nodes[u].h = cnt;
  ++nodes[v].d;
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

void dij(int start) {
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= k; ++j)
      nodes[i].dis[j] = (int)1e9;
  nodes[start].dis[0] = 0, nodes[start].vis = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      heap;
  heap.push(make_pair(nodes[start].dis[0], start));
  while (!heap.empty()) {
    int u = heap.top().second;
    heap.pop();
    if (nodes[u].vis)
      continue;
    nodes[u].vis = 1;
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      int v = edges[i].to;
      nodes[v].dis[0] = min(nodes[v].dis[0], nodes[u].dis[0] + edges[i].to);
      for (int j = 1; j <= k; ++j) {
        nodes[v].dis[j] = min(nodes[v].dis[j], min(nodes[u].dis[j] + edges[i].w,
                                                   nodes[u].dis[j - 1]));
      }
      if (!(--nodes[v].d))
        heap.push(make_pair(nodes[v].dis[k], v));
    }
  }
}

void spfa(int start) {
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= k; ++j)
      nodes[i].dis[j] = (int)1e9;
  queue<int> q;
  q.push(start), nodes[start].dis[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      int v = edges[i].to;
      nodes[v].dis[0] = min(nodes[v].dis[0], nodes[u].dis[0] + edges[i].w);
      for (int j = 1; j <= k; ++j)
        nodes[v].dis[j] = min(nodes[v].dis[j], min(nodes[u].dis[j] + edges[i].w,
                                                   nodes[v].dis[j - 1]));
      if (!(--nodes[v].d))
        q.push(v);
    }
  }
}

signed main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
  }
  dij(1);
  print(nodes[n].dis[k]), putchar('\n');
  return 0;
}