#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int h, dis;
  bool vis;
} nodes[10010];

struct Edge {
  int to, nex, w;
} edges[400010];

int n, m, cnt;

inline int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

inline void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

inline void addedge(int u, int v, int w) {
  edges[++cnt] = (Edge){v, nodes[u].h, w};
  nodes[u].h = cnt;
}

inline int prim(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
    heap;
  // set <pair <double, int> > heap;
  int ret = 0, tot = 0;
  for (register int i = 0; i <= n; ++i) {
    nodes[i].dis = (int)1e9, nodes[i].vis = 0;
  }
  nodes[s].dis = 0;
  for (register int i = 0; i <= n; ++i) {
    heap.push(make_pair(nodes[i].dis, i));
  }
  while (!heap.empty() && tot <= n - 1) {
    int d = heap.top().first;
    int u = heap.top().second;
    heap.pop();
    if (nodes[u].vis) {
      continue;
    }
    nodes[u].vis = 1;
    ++tot;
    ret += nodes[u].dis;
    for (register int i = nodes[u].h; i; i = edges[i].nex) {
      if (edges[i].w < nodes[edges[i].to].dis) {
        nodes[edges[i].to].dis = edges[i].w,
        heap.push(make_pair(nodes[edges[i].to].dis, edges[i].to));
      }
    }
  }
  return ret;
}

int main() {
  n = read(), m = read();
  for (register int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
    addedge(v, u, w);
  }
  int ans = prim(1);
  if (ans >= (int)1e9) {
    puts("orz");
  } else {
    print(ans);
  }
  return 0;
}
