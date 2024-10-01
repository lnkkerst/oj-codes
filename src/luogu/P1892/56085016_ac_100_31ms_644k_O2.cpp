#include <iostream>
using namespace std;

int n, m;
int fa[2010];

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  fa[find(x)] = find(y);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n * 2; ++i) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    char e;
    int p, q;
    cin >> e >> p >> q;
    if (e == 'F') {
      merge(p, q);
    } else {
      merge(p + n, q);
      merge(q + n, p);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += i == fa[i];
  }
  cout << ans;
  return 0;
}
