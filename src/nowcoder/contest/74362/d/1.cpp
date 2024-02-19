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
  int q;
  cin >> q;
  map<int, int> r;
  map<int, int> l;
  map<int, bool> del;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      r[x] = r[y];
      l[r[y]] = x;
      r[y] = x;
      l[x] = y;
      del[x] = false;
    } else {
      int x;
      cin >> x;
      del[x] = true;
      r[l[x]] = r[x];
      l[r[x]] = l[x];
    }
  }
  int cur = 0;
  vector<int> ans;
  while (true) {
    cur = r[cur];
    if (cur != 0 && !del[cur]) {
      ans.emplace_back(cur);
    }
    if (cur == 0) {
      break;
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
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
