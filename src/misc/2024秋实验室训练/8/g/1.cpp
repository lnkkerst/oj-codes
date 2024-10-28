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
  vector<vector<pair<int, int>>> e(n * 3 + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  vector<int> vis(n * 3 + 1);
  vector<int> match;
  for (int i = 1; i <= n * 3; ++i) {
    if (vis[i]) {
      continue;
    }
    for (auto [v, idx] : e[i]) {
      if (vis[v]) {
        continue;
      }
      match.emplace_back(idx);
      vis[i] = vis[v] = true;
      break;
    }
  }
  if (match.size() >= n) {
    cout << "Matching" << endl;
    for (int i = 0; i < n; ++i) {
      cout << match[i] << ' ';
    }
    cout << endl;
  } else {
    cout << "IndSet" << endl;
    int cnt = 0;
    for (int i = 1; i <= n * 3 && cnt < n; ++i) {
      if (!vis[i]) {
        cout << i << ' ';
        ++cnt;
      }
    }
    cout << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
