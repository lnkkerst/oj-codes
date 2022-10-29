#include <bits/stdc++.h>
using namespace std;

struct Node {
  int h, dis, cnt;
  bool vis;
} nodes[100010];

struct Edge {
  int to, nex, w;
} edges[400010];

int n, m, t, cnt;

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
}

bool spfa(int start) {
  queue<int> q;
  q.push(start);
  nodes[start].dis = 0, nodes[start].vis = 1, ++nodes[start].cnt;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    nodes[u].vis = 0;
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      int v = edges[i].to;
      if (nodes[v].dis > nodes[u].dis + edges[i].w) {
        nodes[v].dis = nodes[u].dis + edges[i].w;
        if (!nodes[v].vis) {
          nodes[v].vis = 1, ++nodes[v].cnt;
          if (nodes[v].cnt >= n)
            return 1;
          q.push(v);
        }
      }
    }
  }
  return 0;
}

void work() {
  cnt = 0;
  n = read(), m = read(), cnt = 0;
  for (int i = 1; i <= n; ++i)
    nodes[i] = (Node){0, (int)1e9 + 7, 0, 0};
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
    if (w >= 0)
      addedge(v, u, w);
  }
  printf("%s\n", spfa(1) ? "YE5" : "N0");
  return;
}

int main() {
  t = read();
  while (t--)
    work();
  return 0;
}