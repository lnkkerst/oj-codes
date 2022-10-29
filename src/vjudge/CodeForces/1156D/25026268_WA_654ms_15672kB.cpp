#include <iostream>
using namespace std;

int fa[2][1000010], val[2][1000010];
int n;

int find(int f[], int x) { return x == f[x] ? x : f[x] = find(f, f[x]); }

int merge(int f[], int val[], int u, int v) {
  int fu = find(f, u), fv = find(f, v);
  f[fu] = fv;
  val[fv] += val[fu];
}

int main() {
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    fa[0][i] = fa[1][i] = i;
    val[0][i] = val[1][i] = 1;
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    merge(fa[w], val[w], u, v);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += val[0][find(fa[0], i)] * val[1][find(fa[1], i)] - 1;
  cout << ans;
  return 0;
}