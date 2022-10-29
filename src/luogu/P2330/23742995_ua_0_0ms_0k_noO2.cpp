#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define MAXN 100010

using namespace std;

int read() {
  int ret;
  char ch;
  bool f;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return f ? -ret : ret;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
  return;
}

struct Edge {
  int u, v, w;
} edges[MAXN];

int f[MAXN], n, m, ans = -1, cnt = 0;

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void init() {
  for (int i = 1; i <= n; ++i)
    f[i] = i;
}

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void merge(int x, int y) { f[find(x)] = find(y); }

int main() {
  n = read();
  m = read();
  init();
  for (int i = 1; i <= m; ++i) {
    edges[i].u = read();
    edges[i].v = read();
    edges[i].w = read();
  }
  sort(edges + 1, edges + 1 + m, cmp);
  for (int i = 1; i <= m; ++i) {
    if (find(edges[i].u) != find(edges[i].v)) {
      ans = max(ans, edges[i].w);
      merge(edges[i].u, edges[i].v);
    }
  }
  printf("%d %d\n", n - 1, ans);
  return 0;
}