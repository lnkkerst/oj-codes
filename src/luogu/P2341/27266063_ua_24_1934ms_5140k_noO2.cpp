#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node {
  int h, pre, dfn, low;
  bool vis, inq;
  int col, du, all;
} nodes[100010];

struct Edge {
  int to, nex, w;
} edges[400010];

int n, m, cnt, ans;
int cnt_dfn, cnt_tj;
stack<int> tj;

void addedge(int u, int v) {
  edges[++cnt].nex = nodes[u].h;
  edges[cnt].to = v;
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

void tarjan(int u) {
  nodes[u].low = nodes[u].dfn = ++cnt_dfn;
  tj.push(u);
  for (int i = nodes[u].h; i; i = edges[i].nex) {
    int v = edges[i].to;
    if (!nodes[v].dfn) {
      tarjan(v), nodes[u].low = min(nodes[u].low, nodes[v].low);
    } else if (nodes[v].inq) {
      nodes[u].low = min(nodes[u].low, nodes[v].low);
    }
  }
  if (nodes[u].low == nodes[u].dfn) {
    ++cnt_tj;
    int now;
    do {
      now = tj.top();
      tj.pop();
      nodes[now].inq = 0;
      nodes[now].col = cnt_tj;
      ++nodes[cnt_tj].all;
    } while (u != now);
  }
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    addedge(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!nodes[i].dfn) {
      tarjan(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int u = edges[i].to;
      if (nodes[i].col != nodes[u].col) {
        ++nodes[nodes[i].col].du;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= cnt_tj; ++i) {
    if (!nodes[i].du) {
      if (ans) {
        puts("0");
        return 0;
      }
    }
    ans = i;
  }
  print(nodes[ans].all);
  return 0;
}
