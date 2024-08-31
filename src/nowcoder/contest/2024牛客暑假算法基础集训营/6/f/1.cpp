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

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, map<int, int>> mp;
  vector<int> du(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    ++du[u];
    ++du[v];
    mp[u][v] = mp[v][u] = 1;
  }
  set<int, std::function<bool(const int &, const int &)>> s(
      [&](const int &a, const int &b) {
        if (du[a] == du[b]) {
          return a < b;
        }
        return du[a] < du[b];
      });
  // set<int> s;
  int start = 0;
  for (int i = 1; i <= n; ++i) {
    if (du[i] == n - 1) {
      cout << -1 << endl;
      return;
    }
    if (n - 2 && du[i] == n - 2) {
      start = i;
    } else {
      s.insert(i);
    }
  }

  if (start == 0) {
    start = 1;
    s.erase(1);
  }
  int cur = start;
  cout << cur << ' ';
  while (!s.empty()) {
    for (auto x : s) {
      if (!mp[x][cur]) {
        cur = x;
        cout << cur << ' ';
        s.erase(x);
        break;
      }
    }
  }
  cout << endl;
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
