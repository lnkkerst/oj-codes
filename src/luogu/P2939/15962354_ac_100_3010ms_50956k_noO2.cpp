#include <cstdio>
#include <queue>
#define MAXN 222222

int n, m, k, cnt = 0, tmpp;
bool vis[MAXN] = {false};
int dis[MAXN], head[MAXN];

struct Edge {
  int to, next, w;
} edge[4444444];

int min(int &x, int &y) {
  return x < y ? x : y;
}

void add(int u, int v, int w) {
  cnt++;
  edge[cnt].to = v;
  edge[cnt].next = head[u];
  edge[cnt].w = w;
  head[u] = cnt;
}
std::priority_queue<std::pair<int, int>> q;
void dijkstra(int start) {
  for (int i = 0; i < MAXN; i++) {
    dis[i] = __INT_MAX__;
  }
  q.push(std::make_pair(0, 1));
  dis[start] = 0;

  while (!q.empty()) {
    int p = q.top().second;
    q.pop();
    if (vis[p]) {
      continue;
    }
    vis[p] = 1;
    for (int i = head[p]; i; i = edge[i].next) {
      int y = edge[i].to, z = edge[i].w;
      if (dis[y] > dis[p] + z) {
        dis[y] = dis[p] + z;
        q.push(std::make_pair(-dis[y], y));
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 1; i <= m; i++) {
    int t1, t2, t3;

    scanf("%d%d%d", &t1, &t2, &t3);
    add(t1, t2, t3);
    add(t2, t1, t3);

    for (int j = 1; j <= k; j++) {
      add(j * n + t1, j * n + t2, t3);
      add(j * n + t2, j * n + t1, t3);
      add((j - 1) * n + t1, j * n + t2, 0);
      add((j - 1) * n + t2, j * n + t1, 0);
    }
  }

  tmpp = n;
  dijkstra(1);
  int ans = dis[tmpp];
  for (int i = 1; i <= k; i++) {
    ans = min(ans, dis[i * n + tmpp]);
  }

  printf("%d", ans);

  return 0;
}
