#include <iostream>
using namespace std;

struct Node {
  int h, siz;
  Node(): h(0), siz(1) {}
} a[1001];

struct Edge {
  int to, nex;
  Edge(): to(0), nex(0) {}
  Edge(int _to, int _nex): to(_to), nex(_nex) {}
} e[2001];

int n, cnt;

void addEdge(int u, int v) {
  e[++cnt] = {v, a[u].h};
  a[u].h = cnt;
}

int dfs(int u) {
  for (int i = a[u].h; i; i = e[i].nex) {
    a[u].siz += dfs(e[i].to);
  }
  return a[u].siz;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    addEdge(u, v);
  };
  dfs(1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += a[i].siz;
  }
  cout << ans;
  return 0;
}
