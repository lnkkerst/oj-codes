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
#define endl "\n"

void solve() {
  int m;
  cin >> m;
  map<int, int> b;
  function<void(int x, map<int, int> &)> add = [&](int x, map<int, int> &b) {
    ++b[x];
    if (b[x] >= 3) {
      b[x] -= 2;
      add(x + 1, b);
    }
  };
  while (m--) {
    int t, v;
    cin >> t >> v;

    if (t == 1) {
      add(v, b);
    } else {
      int cur = 0;
      bool fl = true;
      auto tb = b;
      while (v) {
        if (v & 1) {
          if (!tb[cur]) {
            fl = false;
          }
        } else {
          if (tb[cur] == 2) {
            add(cur + 1, tb);
          }
        }
        v >>= 1;
        ++cur;
      }
      if (fl) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
