#include <cstring>
#include <iostream>
using namespace std;

int n, m, e[51][51], ans, u[51 << 1], v[51 << 1];
bool vis[51];

void dfs(int node) {
  vis[node] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i == node)
      continue;
    if (!vis[i] && e[node][i])
      dfs(i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i];
    e[u[i]][v[i]] = e[v[i]][u[i]] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    e[u[i]][v[i]] = e[v[i]][u[i]] = 0;
    memset(vis, 0, sizeof(vis));
    dfs(1);
    for (int i = 1; i <= n; ++i)
      if (!vis[i]) {
        ++ans;
        break;
      }
    e[u[i]][v[i]] = e[v[i]][u[i]] = 1;
  }
  cout << ans;
  return 0;
}