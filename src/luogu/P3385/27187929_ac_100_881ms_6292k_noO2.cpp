#include <cstdio>
#include <cstring>
#include <queue>

const int N_MAX = 300000;
const int M_MAX = 9000000;

struct Edge {
  int start, to, w, next;
  Edge() {}
  Edge(int start, int to, int w, int next)
      : start(start), to(to), w(w), next(next) {}
} edge[N_MAX];

int head[N_MAX], edge_size;

void add_edge(int u, int v, int w) {
  edge[++edge_size] = Edge(u, v, w, head[u]);
  head[u] = edge_size;
}

int dis[N_MAX], cnt[N_MAX], n;
bool vis[N_MAX], flag;
std::queue<int> Q;

void spfa(int u) {
  memset(dis, 0x3f, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  memset(vis, false, sizeof(vis));
  Q.push(u);
  vis[u] = true;
  dis[u] = 0;
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    vis[now] = false;
    for (int e = head[now]; e && e <= edge_size; e = edge[e].next) {
      int v = edge[e].to;
      int w = edge[e].w;
      if (dis[v] > dis[now] + w) {
        cnt[v]++;
        if (cnt[v] >= n) {
          flag = true;
          return;
        }
        dis[v] = dis[now] + w;
        if (!vis[v]) {
          Q.push(v);
          vis[v] = true;
        }
      }
    }
  }
}

int f, m, u, v, w;

int main() {
  scanf("%d", &f);
  for (int i = 1; i <= f; i++) {
    memset(head, 0, sizeof(head));
    edge_size = 0;
    flag = false;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
      scanf("%d %d %d", &u, &v, &w);
      add_edge(u, v, w);
      if (w >= 0)
        add_edge(v, u, w);
    }
    spfa(1);
    if (flag)
      printf("YE5\n");
    else
      printf("N0\n");
  }
}