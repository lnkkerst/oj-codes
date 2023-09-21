#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  vector<int> bk(100);
  int xo = 0;
  int bo = 0;
  for (auto &i : a) {
    cin >> i;
    for (int j = 0; j <= 32; ++j) {
      if ((i >> j) & 1) {
        ++bk[j];
      }
    }
    xo ^= i;
  }
  for (auto &i : b) {
    cin >> i;
    bo |= i;
  }
  b.emplace_back(bo);
  int mi = xo, ma = xo;
  for (auto x : b) {
    int tx = 0;
    for (int i = 0; i <= 32; ++i) {
      int cur = bk[i];
      if ((x >> i) & 1) {
        cur = n;
      }
      if (cur & 1) {
        tx += (1 << i);
      }
    }
    ma = max(tx, ma);
    mi = min(mi, tx);
  }
  cout << mi << ' ' << ma << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
