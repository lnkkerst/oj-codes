#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;

struct Node {
  int h, dis;
  bool vis;
} nodes[1000010];

struct Edge {
  int to, nex, w;
} edges[6000010];

int n, m, cnt;
int st, ed;

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

void addedge(int u, int v, int w) {
  edges[++cnt] = (Edge){v, nodes[u].h, w};
  nodes[u].h = cnt;
  edges[++cnt] = (Edge){u, nodes[v].h, w};
  nodes[v].h = cnt;
}

int dij(int start) {
  for (int i = 1; i <= n * m * 2; ++i)
    nodes[i].dis = (int)1e9;
  nodes[start].dis = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      heap;
  heap.push(make_pair(nodes[start].dis, start));
  while (!heap.empty()) {
    int u = heap.top().second;
    heap.pop();
    if (nodes[u].vis)
      continue;
    nodes[u].vis = 1;
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      int v = edges[i].to;
      if (nodes[v].dis > nodes[u].dis + edges[i].w) {
        nodes[v].dis = nodes[u].dis + edges[i].w;
        if (!nodes[v].vis)
          heap.push(make_pair(nodes[v].dis, v));
      }
    }
  }
  return nodes[ed].dis;
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
  print(dij(st));
  return 0;
}