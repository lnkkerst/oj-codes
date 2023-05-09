#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

struct Node {
  int fa;
  vector<int> edges;
  int dis;
  bool vis;
};

vector<Node> a;

void dfs(int u) {
  if (a[u].vis) {
    return;
  }
  a[u].vis = true;
  for (auto v : a[u].edges) {
    if (v == a[u].fa) {
      continue;
    }
    a[v].fa = u;
    a[v].dis = a[u].dis + 1;
    dfs(v);
  }
}

void solve() {
  int n, k, c;
  cin >> n >> k >> c;
  a.clear();
  a.resize(n + 1);
  a[1].fa = 1;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    a[u].edges.emplace_back(v);
    a[v].edges.emplace_back(u);
  }
  if (n == 2) {
    cout << k << endl;
    return;
  }
  dfs(1);
  vector<int> b;
  b.reserve(n * 2);
  for (int i = 1; i <= n; ++i) {
    b.emplace_back(a[i].dis);
  }
  sort(b.begin(), b.end(), greater<>());
  if (k <= c) {
    cout << b[0] * k << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
  }
  int ans = b[0] * k;
  for (int i = 1; i <= b[1]; ++i) {
    ans = max(ans, (b[0] + i) * k - c * i);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
