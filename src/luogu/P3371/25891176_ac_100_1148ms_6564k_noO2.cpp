#include <bits/stdc++.h>
using namespace std;

struct Node {
  int dis, inq, h;
} nodes[10010];

struct Edge {
  int to, w;
  int nex;
} edges[500010];

int n, m, s;
int cnt;

void addedge(int u, int v, int w) {
  edges[++cnt].nex = nodes[u].h;
  edges[cnt].to = v;
  edges[cnt].w = w;
  nodes[u].h = cnt;
}

void spfa(int start) {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    nodes[i].dis = 2147483647;
  }
  nodes[start].dis = 0, nodes[start].inq = 1;
  q.push(start);
  while (!q.empty()) {
    int u = q.front();
    nodes[u].inq = 0;
    q.pop();
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      int v = edges[i].to;
      if (nodes[v].dis > nodes[u].dis + edges[i].w) {
        nodes[v].dis = nodes[u].dis + edges[i].w;
        if (!nodes[v].inq) {
          nodes[v].inq = 1;
          q.push(v);
        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> s;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    addedge(u, v, w);
  }
  spfa(s);
  for (int i = 1; i <= n; ++i) {
    cout << nodes[i].dis << ' ';
  }
  return 0;
}
