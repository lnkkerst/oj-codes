#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
  int h, dis;
  bool vis;
  Node(int _h = 0, int _dis = (int)1e9, bool _vis = 0) {
    h = _h, dis = _dis;
    vis = _vis;
  }
} nodes[100010];

struct Edge {
  int to, nex, w;
} edges[400010];

int n, m, s, cnt = 0;

void addedge(int u, int v, int w) {
  edges[++cnt] = (Edge){v, nodes[u].h, w};
  nodes[u].h = cnt;
}

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

void dij(int start) {
  for (int i = 1; i <= n; ++i) {
    nodes[i].dis = (int)1e9;
  }
  nodes[start].dis = 0, nodes[start].vis = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
    heap;
  heap.push(make_pair(nodes[start].dis, s));
  while (!heap.empty()) {
    int u = heap.top().second;
    heap.pop();
    if (nodes[u].vis) {
      continue;
    }
    nodes[u].vis = 1;
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      int v = edges[i].to;
      if (nodes[v].dis > nodes[u].dis + edges[i].w) {
        nodes[v].dis = nodes[u].dis + edges[i].w;
        if (!nodes[v].vis) {
          heap.push(make_pair(nodes[v].dis, v));
        }
      }
    }
  }
}

int main() {
  n = read(), m = read(), s = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
  }
  dij(s);
  for (int i = 1; i <= n; ++i) {
    print(nodes[i].dis), putchar(' ');
  }
  return 0;
}
