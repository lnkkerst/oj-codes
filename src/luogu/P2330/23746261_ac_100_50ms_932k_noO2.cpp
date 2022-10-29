#include <algorithm>
#include <iostream>
#define MAXN 100010

using namespace std;

struct Edge {
  int u, v, w;
} edges[MAXN];

int n, m, f[MAXN], ans, cnt;

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void init() {
  for (int i = 1; i <= n; ++i)
    f[i] = i;
}

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void merge(int x, int y) { f[find(x)] = find(y); }

int main() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= m; ++i)
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  sort(edges + 1, edges + 1 + m, cmp);
  for (int i = 1; i <= m; ++i) {
    if (find(edges[i].u) != find(edges[i].v)) {
      ans = max(ans, edges[i].w);
      merge(edges[i].u, edges[i].v);
      ++cnt;
    }
    if (cnt == n - 1)
      break;
  }
  cout << n - 1 << " " << ans;
  return 0;
}
