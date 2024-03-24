#pragma GCC optimize(2)
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

#define int long long

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int TOP = 2e4;
  int ans = 1e9;
  vector<int> ansa(3);
  for (int x = 1; x <= TOP; ++x) {
    for (int i = 1; i * x <= TOP; ++i) {
      for (int j = 1; i * j * x <= TOP; ++j) {
        int na = x;
        int nb = i * x;
        int nc = i * j * x;
        int t = 0;
        t += abs(a - na);
        t += abs(b - nb);
        t += abs(c - nc);
        if (t < ans) {
          ans = t;
          ansa[0] = na;
          ansa[1] = nb;
          ansa[2] = nc;
        }
      }
    }
  }
  cout << ans << endl;
  for (auto i : ansa) {
    cout << i << ' ';
  }
  cout << endl;
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
