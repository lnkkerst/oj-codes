#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;

struct Node {
  int h, dis, cnt;
  bool vis;
} nodes[233333];

struct Edge {
  int to, nex, w;
} edges[2333333];

int n, k, cnt, ans;

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

bool spfa(int st) {
  queue<int> q;
  nodes[st].vis = 1;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    nodes[u].vis = 0;
    q.pop();
    if (nodes[u].cnt == n - 1)
      return 0;
    ++nodes[u].cnt;
    for (int i = nodes[u].h; i; i = edges[i].nex) {
      int v = edges[i].to;
      if (nodes[v].dis < nodes[u].dis + edges[i].w) {
        nodes[v].dis = nodes[u].dis + edges[i].w;
        if (!nodes[v].vis) {
          nodes[v].vis = 1;
          q.push(v);
        }
      }
    }
  }
  return 1;
}

signed main() {
  n = read(), k = read();
  for (int i = 1; i <= k; ++i) {
    int opt = read(), u = read(), v = read();
    if (opt == 1)
      addedge(u, v, 0), addedge(v, u, 0);
    else if (opt == 2)
      addedge(u, v, 1);
    else if (opt == 3)
      addedge(v, u, 0);
    else if (opt == 4)
      addedge(v, u, 1);
    else
      addedge(u, v, 0);
  }
  for (int i = n; i >= 1; --i)
    addedge(0, i, 1);
  if (spfa(0)) {
    for (int i = 1; i <= n; ++i)
      ans += nodes[i].dis;
    print(ans);
  } else
    print(-1);
  return 0;
}