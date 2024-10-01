#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
  int h, v, ind;
  bool vis;
} a[200010];

struct Edge {
  int to, nex;
} e[2000010];

int n, ans, cnt = 0, no = 0;
string xs, nm, fa, tmp;
unordered_map<string, int> id;

void addedge(int u, int v) {
  e[++cnt] = (Edge){v, a[u].h};
  a[u].h = cnt;
  ++a[v].ind;
}

void topo() {
  queue<int> q;
  for (int i = 1; i <= no; ++i) {
    if (!a[i].ind) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    a[u].vis = 1;
    q.pop();
    for (int i = a[u].h; i; i = e[i].nex) {
      int v = e[i].to;
      --a[v].ind;
      a[v].v = max(a[v].v, a[u].v + 1);
      ans = max(ans, a[v].v);
      if (!a[v].ind) {
        q.push(v);
      }
    }
  }
}

void dfs(int u, int &val, int &dep) {
  a[u].vis = 1;
  val = max(val, a[u].v);
  ++dep;
  for (int i = a[u].h; i; i = e[i].nex) {
    if (!a[e[i].to].vis) {
      dfs(e[i].to, val, dep);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> xs >> nm >> tmp >> tmp >> fa;
    nm = xs + ' ' + nm;
    fa = xs + ' ' + fa;
    if (!id[nm]) {
      id[nm] = ++no;
    }
    if (!id[fa]) {
      id[fa] = ++no;
    }
    addedge(id[nm], id[fa]);
  }
  topo();
  for (int i = 1; i <= no; ++i) {
    if (!a[i].vis) {
      int val = 0, dep = 0;
      dfs(i, val, dep);
      ans = max(ans, val + dep);
    }
  }
  cout << ans;
  return 0;
}
