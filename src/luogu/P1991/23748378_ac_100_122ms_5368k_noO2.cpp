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
#define MAXN 250010

using namespace std;

struct Edge {
  int u, v;
  double w;
} edges[MAXN];

int n, m, f[MAXN], cnt, x[5010], y[5010];
double ans = 0;

bool cmp(Edge a, Edge b) {
  return a.w < b.w;
}

void init(int x) {
  for (int i = 1; i <= x; ++i) {
    f[i] = i;
  }
}

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
  f[find(x)] = find(y);
}

int main() {
  int s;
  cin >> s >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; j++) {
      edges[++cnt].u = i;
      edges[cnt].v = j;
      edges[cnt].w = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    }
  }
  init(cnt);
  int cnt2 = n;
  sort(edges + 1, edges + 1 + cnt, cmp);
  for (int i = 1; i <= cnt; ++i) {
    if (find(edges[i].u) != find(edges[i].v)) {
      ans = max(ans, edges[i].w);
      merge(edges[i].u, edges[i].v);
      cnt2--;
    }
    if (cnt2 == s) {
      break;
    }
  }
  printf("%.2lf", ans);
  return 0;
}
