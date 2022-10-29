#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int fa[200010], tr[200010];
bool b[200010];
int n, m, t, cnt;

void init(int tot) {
  memset(fa, 0, sizeof(fa));
  memset(tr, 0, sizeof(tr));
  memset(b, 0, sizeof(b));
  cnt = 0;
  for (int i = 0; i < n; ++i)
    fa[i] = tr[i] = i;
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int x, int y) { fa[find(x)] = find(y); }

void sepa(int x) {
  tr[x] = ++cnt + n - 1;
  fa[tr[x]] = tr[x];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  while (233) {
    cin >> n >> m;
    if (!n || !m)
      return 0;
    init(n);
    for (int i = 1; i <= m; ++i) {
      char opt;
      cin >> opt;
      if (opt == 'M') {
        int a, b;
        cin >> a >> b;
        merge(tr[a], tr[b]);
      } else {
        int x;
        cin >> x;
        sepa(x);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int tmp = find(tr[i]);
      if (!b[tmp])
        ++ans, b[tmp] = 1;
    }
    cout << "Case #" << ++t << ": " << ans << endl;
  }
}