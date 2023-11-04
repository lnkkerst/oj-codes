#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  vector<int> cells[12];
  cells[2].emplace_back(1);
  cells[3].emplace_back(2);
  cells[4].emplace_back(3);
  unordered_map<int, int> b;
  b[1] = 2;
  b[2] = 3;
  b[3] = 4;
  for (int i = 1; i <= 12; ++i) {
    int c, x;
    cin >> c >> x;
    vector<int> t;
    while (true) {
      int u = cells[b[c]].back();
      cells[b[c]].pop_back();
      t.emplace_back(u);
      if (u == c) {
        break;
      }
    }
    int to = b[c] + x;
    while (!t.empty()) {
      int u = t.back();
      t.pop_back();
      cells[to].emplace_back(u);
      b[u] = to;
    }
  }
  if (cells[9].size() == 3) {
    cout << "Y" << endl;
  } else {
    cout << "N" << endl;
  }
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
