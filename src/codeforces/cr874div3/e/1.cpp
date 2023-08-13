#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<unordered_set<int>> e(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    e[i].insert(a[i]);
    e[a[i]].insert(i);
  }
  int ma = 0;
  for (int i = 1; i <= n; ++i) {
    ma += e[i].size() == 1;
  }
  ma /= 2;
  int mi = 0;
  vector<int> b1(n + 1);
  int ct = 0;

  for (int i = 1; i <= n; ++i) {
    if (e[i].size() != 1) {
      continue;
    }
    if (b1[i]) {
      continue;
    }
    ++ct;
    int u = i, fa = -1;
    while (true) {
      b1[u] = true;
      if (e[u].size() == 1 && *e[u].begin() == fa) {
        break;
      }
      auto v = *e[u].begin();
      if (v == fa) {
        auto it = e[u].begin();
        ++it;
        v = *it;
      }
      fa = u;
      u = v;
    }
  }
  int ct2 = 0;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (e[i].size() == 1) {
      continue;
    }
    if (b1[i]) {
      continue;
    }
    if (b[i]) {
      continue;
    }
    int c = ++mi;
    int u = i, fa = -1;
    while (true) {
      // cout << u << ' ';
      if (b[u]) {
        break;
      }
      b[u] = c;
      ++ct2;
      auto v = *e[u].begin();
      if (v == fa) {
        auto it = e[u].begin();
        ++it;
        v = *it;
      }
      fa = u;
      u = v;
    }
  }
  cout << mi + (ct2 != n) << ' ' << ma + mi << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
