#include <algorithm>
#include <cctype>
#include <cstdio>

struct Edge {
  int u, v, w;
} edges[100010];

int m, n;
int fa[100010];
int sta[100010];

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (fl = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * fl;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int kru(int del) {
  int ret = 0;
  for (int i = 1; i <= m; ++i)
    fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    if (i == del)
      continue;
    int f1 = find(edges[i].u);
    int f2 = find(edges[i].v);
    if (f1 == f2)
      continue;
    fa[f1] = f2;
    ret += edges[i].w;
  }
  return ret;
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i)
    edges[i].u = read(), edges[i].v = read(), edges[i].w = read();
  std::sort(edges + 1, edges + m + 1, cmp);
  int full = kru(0), ans1 = 0, ans2 = 0;
  for (int i = 1; i <= m; ++i)
    if (kru(i) != full)
      ++ans1, ans2 += edges[i].w;
  print(ans1), putchar(' '), print(ans2);
}