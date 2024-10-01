#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;

struct Edge {
  int v, w, nex;
} edges[MAXN * MAXN << 2];

struct Node {
  int h, dis;
  bool vis;
} nodes[MAXN * MAXN << 1];

int read() {
  int ret;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

int n, m, cnt, cx, cy, dx, dy;
bool e[MAXN * MAXN << 1];

int toli(int x, int y) {
  return n * (x - 1) + y;
}

void toma(int u, int &x, int &y) {
  x = u / n;
  y = u & n;
}

void addedge(int u, int v, int w) {
  edges[++cnt] = (struct Edge){v, w, nodes[u].h};
  nodes[u].h = cnt;
}

void dij(int s) {
  for (int i = 1; i <= n * m << 1; ++i) {
    nodes[i].dis = 0x7fffffff;
  }
  nodes[s].dis = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
    heap;
  heap.push(make_pair(nodes[s].dis, s));
  while (!heap.empty()) {
    int u = heap.top().second;
    heap.pop();
    if (nodes[u].vis) {
      continue;
    }
    nodes[u].vis = 1;
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      if (nodes[u].dis + edges[i].w < nodes[edges[i].v].dis) {
        nodes[edges[i].v].dis = nodes[u].dis + edges[i].w;
        if (!nodes[edges[i].v].vis) {
          heap.push(make_pair(nodes[edges[i].v].dis, edges[i].v));
        }
      }
    }
  }
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch = getchar();
      while (ch != '#' && ch != 'C' && ch != '.' && ch != 'D') {
        ch = getchar();
      }
      if (ch == 'C') {
        cx = i, cy = j;
      }
      if (ch == 'D') {
        dx = i, dy = j;
      }
      if (ch == '#') {
        e[toli(i, j)] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!e[toli(i, j)]) {
        if (i < n) {
          if (e[toli(i + 1, j)]) {
            addedge(toli(i, j), toli(i, j) + m * n, 1);
            if (j < m && !e[toli(i, j + 1)]) {
              addedge(toli(i, j), toli(i, j + 1), 0);
            }
            if (j > 1 && !e[toli(i, j - 1)]) {
              addedge(toli(i, j), toli(i, j - 1), 0);
            }
          } else {
            addedge(toli(i, j), toli(i + 1, j), 0);
          }
        }
        if (i > 1) {
          if (e[toli(i - 1, j)]) {
            addedge(toli(i, j) + m * n, toli(i, j), 1);
            if (j < m && !e[toli(i, j + 1) + m * n]) {
              addedge(toli(i, j) + m * n, toli(i, j + 1) + m * n, 0);
            }
            if (j > 1 && !e[toli(i, j - 1) + m * n]) {
              addedge(toli(i, j) + m * n, toli(i, j - 1) + m * n, 0);
            }
          } else {
            addedge(toli(i, j) + m * n, toli(i - 1, j) + m * n, 0);
          }
        }
      }
    }
  }
  dij(toli(cx, cy));
  int ans = min(nodes[toli(dx, dy)].dis, nodes[toli(dx, dy) + m * n].dis);
  printf("%d\n", ans == 0x7fffffff ? -1 : ans);
  return 0;
}
