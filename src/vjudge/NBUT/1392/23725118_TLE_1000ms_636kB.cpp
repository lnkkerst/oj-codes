#include <iostream>
using namespace std;
int fa[50010], n, m, v, u, ans;
void init(int x) {
  for (int i = 1; i <= x; ++i) {
    fa[i] = i;
  }
}
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v) {
  fa[find(u)] = find(v);
}
void work() {
  init(n), ans = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v, merge(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    if (fa[i] == i) {
      ++ans;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  while (cin >> n >> m) {
    work();
  }
  return 0;
}
