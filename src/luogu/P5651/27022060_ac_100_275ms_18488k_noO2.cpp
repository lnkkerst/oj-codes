#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#define int long long
using namespace std;

struct Node {
  int dis, inq, h;
} nodes[200100];

struct Edge {
  int to, w;
  int nex;
} edges[1000010];

int n, m, q, cnt;

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
      if (nodes[v].dis > (nodes[u].dis ^ edges[i].w)) {
        nodes[v].dis = (nodes[u].dis ^ edges[i].w);
        if (!nodes[v].inq) {
          nodes[v].inq = 1;
          q.push(v);
        }
      }
    }
  }
}

signed main() {
  n = read(), m = read(), q = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
    addedge(v, u, w);
  }
  srand(time(NULL));
  spfa(rand() % n + 1);
  for (int i = 1; i <= q; ++i) {
    int u = read(), v = read();
    print((nodes[u].dis ^ nodes[v].dis));
    putchar('\n');
  }
  return 0;
}
