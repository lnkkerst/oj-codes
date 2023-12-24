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
  int n;
  cin >> n;
  vector<int> l(n), r(n), c(n);
  for (auto &i : l) {
    cin >> i;
  }
  for (auto &i : r) {
    cin >> i;
  }
  for (auto &i : c) {
    cin >> i;
  }
  vector<int> il(n), ir(n), ic(n);
  for (int i = 0; i < n; ++i) {
    il[i] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    ir[i] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    ic[i] = i + 1;
  }
  int ans = 1e18;
  do {
    do {
      do {
        auto nl = l, nr = r, nc = c;
        for (int i = 0; i < n; ++i) {
          nl[i] = l[il[i] - 1];
        }
        for (int i = 0; i < n; ++i) {
          nr[i] = r[ir[i] - 1];
        }
        for (int i = 0; i < n; ++i) {
          nc[i] = c[ic[i] - 1];
        }
        bool fl = false;
        for (int i = 0; i < n; ++i) {
          if (nl[i] > nr[i]) {
            fl = true;
            break;
          }
        }
        if (fl) {
          continue;
        }
        int t = 0;
        for (int i = 0; i < n; ++i) {
          t += nc[i] * (nr[i] - nl[i]);
        }
        ans = min(ans, t);
      } while (next_permutation(ic.begin(), ic.end()));
    } while (next_permutation(ir.begin(), ir.end()));
  } while (next_permutation(il.begin(), il.end()));
  cout << ans << endl;
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
