#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<int> fa(n + 1);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  function<int(int)> find = [&](int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
  };
  auto merge = [&](int x, int y) {
    fa[find(x)] = find(y);
  };
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    if (find(x) == find(y)) {
      ++ans;
    }
    merge(x, y);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
